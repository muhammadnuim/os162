# REV02 Wed Sep 28 15:41:09 WIB 2016
# REV01 Mon Sep 26 14:47:16 WIB 2016
# REV00 Tue Sep 20 16:56:25 WIB 2016
# START Tue Sep 13 11:44:18 WIB 2016

CC=gcc

EXECS= \
	00-global-char  \
	01-local-char   \
	02-global-char  \
	03-global-char  \
    52-open-close   \
    54-write        \
	59-readwrite	\

DEMOFILES=\
	demo-file1.txt \
	demo-file2.txt \
	demo-file3.txt \
	demo-file5.txt \
	demo-file9.txt \


all:  $(EXECS)

00-global-char: 00-global-char.c
	$(CC) -o 00-global-char 00-global-char.c

01-local-char: 01-local-char.c
	$(CC) -o 01-local-char 01-local-char.c

02-global-char: 02-global-char.c
	$(CC) -o 02-global-char 02-global-char.c

03-global-char: 03-global-char.c
	$(CC) -o 03-global-char 03-global-char.c

52-open-close: 52-open-close.c
	$(CC) -o 52-open-close 52-open-close.c

54-write: 54-write.c
	$(CC) -o 54-write 54-write.c

59-readwrite: 59-readwrite.c
	$(CC) 59-readwrite.c -o 59-readwrite -Xlinker -Map=59-readwrite.map

clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
