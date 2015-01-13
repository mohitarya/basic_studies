#Make file to compile static Library
#variables for compiler
CC = gcc
CFLAGS = -c
SOURCE = static_lib.c
TESTSOURCE = test_prog.c
OBJSOURCE = static_lib.o
LIBTARGET_NAME = static_lib.a
TESTBINFILE = test_prog
OBJTARGET = objstaticlib 
DEPS = static_lib.h
LIBTARGET = staticlib
TESTTARGET = testprog

#define Command
AR = ar
RM = rm -rf

all: $(LIBTARGET) $(TESTTARGET)

$(LIBTARGET): $(OBJSOURCE)
	$(AR) rcs $(LIBTARGET_NAME) $(OBJSOURCE)

$(OBJTARGET): $(SOURCE) 
	$(CC) $(CFLAGS) $(SOURCE) -o $(OBJSOURCE)

$(TESTTARGET): $(TESTSOURCE) $(LIBTARGET_NAME)
	$(CC) -o $(TESTBINFILE) $(TESTSOURCE) -ldl $(LIBTARGET_NAME)

clean:
	$(RM) *.o *.a test_prog
