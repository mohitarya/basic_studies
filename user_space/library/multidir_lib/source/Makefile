CC = gcc
CFLAGS = -c
DYNAMICLIBPATH = ../dynamic_lib/
STATICLIBPATH = ../static_lib/
all: lib_prog.o static_lib.a libdynamic.so
	$(CC) -L$(DYNAMICLIBPATH) -o lib_prog lib_prog.o -ldl $(STATICLIBPATH)/static_lib.a -ldynamic

lib_prog.o: lib_prog.c
	$(CC) $(CFLAGS) lib_prog.c

static_lib.a:
	cd $(STATICLIBPATH); make

libdynamic.so:
	cd $(DYNAMICLIBPATH); make
clean:
	rm -rf *.o lib_prog
	cd $(STATICLIBPATH); make clean
	cd $(DYNAMICLIBPATH); make clean
