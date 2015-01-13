#Makefile to create dynamic Library
#define variables
SOURCE = dynamic_lib.c
OBJFILE = dynamic_lib.o
TARGETFILE = libdynamic.so
CFLAGS = -c -fpic
LFLAGS = -shared

#define commands
CC = gcc
COPY = /bin/cp
CHMOD = /usr/bin/chmod
LDCONFIG = /usr/sbin/ldconfig
RM = rm -rf

libdynamic.so: dynamic_lib.o
	$(CC) $(LFLAGS) -o $(TARGETFILE) $(OBJFILE)
	$(COPY) -f $(TARGETFILE) /usr/lib/
	$(CHMOD) 0755 /usr/lib/$(TARGETFILE)
	$(LDCONFIG)
dynamic_lib.o: $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE)

clean:
	$(RM) *.so *.o
