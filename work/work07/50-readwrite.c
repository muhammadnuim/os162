/*
 * (c) 2011-2016 Rahmat M. Samik-Ibrahim -- This is free software
 * Feel free to copy and/or modify and/or distribute it, 
 * provided this notice, and the copyright notice, are preserved. 
 * REV01 Wed Nov  2 13:49:55 WIB 2016
 * REV00 Xxx Sep 30 XX:XX:XX UTC 2015
 * START Xxx Mar 30 02:13:01 UTC 2011
 */

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include "99-myutils.h"

extern sem_t    mutex, db, empty, full, rmutex, wmutex;

#define R_REHAT 4000
#define R_READ  2000
#define R_JUMLAH   3

#define W_REHAT 3000
#define W_WRITE 2000
#define W_JUMLAH   2

int reader_ID = 0;
int writer_ID = 0;

sem_t reading, writing;

int reader = 0;
int writer = 0;

void* Reader (void* a) {
   int  my_ID;

   sem_wait (&rmutex);
   my_ID  = reader_ID++;
   sem_post (&rmutex);

   while (TRUE) {
      sem_wait(&rmutex);
      if (reader==0) sem_wait(&writing);
      reader++;
      printf("			    READER %d: READ\n", my_ID);
      startRead();
      printf("                        READER %d: READING\n", my_ID);
      endRead();
      printf("                        READER %d: DONE READING\n", my_ID);

      if (reader == R_JUMLAH) {
         reader = 0;
         sem_post (&reading);
      }
      sem_post (&rmutex);
      rehat_acak(R_READ);
   }
}

void* Writer (void* a) {
   int  my_ID;

   sem_wait (&wmutex);
   my_ID  = writer_ID++;
   sem_post (&wmutex);


   while (TRUE) {
      sem_wait(&wmutex);
      if (writer == 0) sem_wait(&reading);
      writer++;
      startWrite();
      printf("WRITER %d: WRITING\n", my_ID);
      endWrite();
      printf("WRITER %d: DONE WRITING\n", my_ID);
      if (writer == W_JUMLAH) {
         writer = 0;
         sem_post (&writing);
      }
      sem_post (&wmutex);
      rehat_acak(W_WRITE);
   }
}

int main(int argc, char * argv[])
{
   int ii;
   init_rw();
   sem_init(&writing, 0, 0);
   sem_init(&reading, 0, 1);

   for (ii = 0 ; ii < R_JUMLAH; ii++)
      daftar_trit(Reader);
   for (ii = 0 ; ii < W_JUMLAH; ii++)
      daftar_trit(Writer);
   jalankan_trit();
   beberes_trit("Selese...");
}

