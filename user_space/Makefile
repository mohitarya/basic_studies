#Makefile to compile all the targets or single target
STATICLIBPATH = ./library/static_lib/
DYNAMICLIBPATH = ./library/dynamic_lib/
STAT_DYN_LIB_PATH = ./library/ 
STATICTARGET = staticlib
DYNAMICTARGET = dynamiclib
STAT_DYN_TARGET = all_lib_build
CD = cd
TARG = $(STATICTARGE) $((DYNAMICTARGET) $(STAT_DYN_TARGET)

all: $(TARG)

$(STATICTARGET): 
	$(CD) $(STATICLIBPATH); make

$(DYNAMICTARGET):
	$(CD) $(DYNAMICLIBPATH); make

$(STAT_DYN_TARGET):
	$(CD) $(STAT_DYN_LIB_PATH); make

clean:
	$(CD) $(STATICLIBPATH); make clean
	$(CD) $(DYNAMICLIBPATH); make clean
	$(CD) $(STAT_DYN_LIB_PATH); make clean
