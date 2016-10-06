/*
 * (c) 2015-2016 Rahmat M. Samik-Ibrahim -- This is free software
 * REV00 Mon Sep 26 18:23:45 WIB 2016
 * START Xxx Apr 25 XX:XX:XX WIB 2015
 */

#define  FILE1   "demo-file5.txt"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

static char *str1 = "AAAXBBB\n";
static char *str2 = "CCC\n";
static char *str3 = "DDDDDDDDD\n";

void main() {
   int fd1, fd2;
   fd1 = open (FILE1, O_RDWR | O_CREAT, 0644);
   fd2 = open (FILE1, O_RDWR | O_CREAT, 0644);
   printf("File Descriptors --- fd1 = %d, fd2 = %d\n", fd1, fd2);
   write(fd1, str1, strlen(str1));
   write(fd2, str2, strlen(str2));
}

