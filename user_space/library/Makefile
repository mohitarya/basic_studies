#Makefile to compile all the targets or single target
STATICLIBPATH = static_lib/
DYNAMICLIBPATH = dynamic_lib/
MULTIDIRLIBPATH = multidir_lib/source/

TARG = staticlib dynamiclib multilib 

all: $(TARG)

staticlib: 
	make -C $(PWD)/$(STATICLIBPATH)

dynamiclib:
	make -C $(PWD)/$(DYNAMICLIBPATH)

multilib:
	make -C $(PWD)/$(MULTIDIRLIBPATH)

clean:
	make -C $(PWD)/$(STATICLIBPATH) clean
	make -C $(PWD)/$(DYNAMICLIBPATH) clean
	make -C $(PWD)/$(MULTIDIRLIBPATH) clean
