#Makefile to compile all the targets or single target
STATICLIBPATH = static_lib/
DYNAMICLIBPATH = dynamic_lib/
SOURCE = source/
CD = cd
TARG = staticlib dynamiclib lib_prog

all: $(TARG)

staticlib: 
	$(CD) $(STATICLIBPATH); make

dynamiclib:
	$(CD) $(DYNAMICLIBPATH); make

lib_prog:
	$(CD) $(SOURCE); make

clean:
	$(CD) $(STATICLIBPATH); make clean
	$(CD) $(DYNAMICLIBPATH); make clean
	$(CD) $(SOURCE); make clean
