#Make file to compile static Library
#variables for compiler
CC = gcc
CFLAGS = -c
SOURCE = static_lib.c
OBJSOURCE = static_lib.o
LIBTARGET_NAME = static_lib.a
OBJTARGET = objstaticlib 
DEPS = static_lib.h
LIBTARGET = staticlib

#define Command
AR = ar
RM = rm -rf

all: $(LIBTARGET) $(OBJTARGET)

$(LIBTARGET): $(OBJSOURCE)
	$(AR) rcs $(LIBTARGET_NAME) $(OBJSOURCE)

$(OBJTARGET): $(SOURCE) 
	$(CC) $(CFLAGS) $(SOURCE) -o $(OBJSOURCE)

clean:
	$(RM) *.o *.a
