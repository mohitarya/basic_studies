#Makefile to create dynamic Library
#define variables
SOURCE = dynamic_lib.c
TESTSOURCE = test_prog.c
OBJFILE = dynamic_lib.o
TESTBINFILE = test_prog
TARGETFILE = libdynamic.so
LIBTARGET = dynamiclib
TESTTARGET = testprog
OBJTARGET = objfile
CFLAGS = -c -fpic
LFLAGS = -shared

#define commands
CC = gcc
COPY = /bin/cp
CHMOD = /usr/bin/chmod
LDCONFIG = /usr/sbin/ldconfig
RM = rm -rf

all: $(LIBTARGET) $(TESTTARGET)

$(LIBTARGET): $(OBJFILE)
	$(CC) $(LFLAGS) -o $(TARGETFILE) $(OBJFILE)
	$(COPY) -f $(TARGETFILE) /usr/lib/
	$(CHMOD) 0755 /usr/lib/$(TARGETFILE)
	$(LDCONFIG)

$(OBJTARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE)

$(TESTTARGET): $(TESTSOURCE)
	$(CC) -o $(TESTBINFILE) $(TESTSOURCE) -ldynamic

clean:
	$(RM) *.so *.o test_prog
