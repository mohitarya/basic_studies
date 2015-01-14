#Makefile to compile all the targets or single target
STATICLIBPATH = ./static_lib/
DYNAMICLIBPATH = ./dynamic_lib/
MULTIDIRLIBPATH = ./multidir_lib/source/
STATICTAGET = staticlib
DYNAMICTARGET = dynamiclib
MULTILIBTARGET = multilib
CD = cd
TARG = $(STATICTAGET) $(DYNAMICTARGET) $(MULTILIBTARGET)

all: $(TARG)

$(STATICTAGET): 
	$(CD) $(STATICLIBPATH); make

$(DYNAMICTARGET):
	$(CD) $(DYNAMICLIBPATH); make

$(MULTILIBTARGET):
	$(CD) $(MULTIDIRLIBPATH); make

clean:
	$(CD) $(STATICLIBPATH); make clean
	$(CD) $(DYNAMICLIBPATH); make clean
	$(CD) $(MULTIDIRLIBPATH); make clean
