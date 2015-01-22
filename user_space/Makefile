#Makefile to compile all the targets or single target
STATICLIBPATH = library/static_lib/
DYNAMICLIBPATH = library/dynamic_lib/
STAT_DYN_LIB_PATH = library/ 
FORKPATH = fork/
MUTEXPATH = mutex/
PIPEPATH = pipe/
SEMAPHOREPATH = semaphore/
SIGNALPATH = signals/
THREADPATH = threads/
SOCKETPATH = socket/
SHAREDMEMPATH = sharedmemory/
CD = cd
TARG = staticlib dynamiclib all_lib_build buildfork buildmutex buildpipe buildsemaphore buildsignal buildthreads buildsocket sharedmem 

all: $(TARG)

staticlib: 
	make -C $(PWD)/$(STATICLIBPATH)

dynamiclib:
	make -C $(PWD)/$(DYNAMICLIBPATH)

all_lib_build:
	make -C $(PWD)/$(STAT_DYN_LIB_PATH)

buildfork:
	make -C $(PWD)/$(FORKPATH)

buildmutex:
	make -C $(PWD)/$(MUTEXPATH)

buildpipe:
	make -C $(PWD)/$(PIPEPATH)

buildsemaphore:
	make -C $(PWD)/$(SEMAPHOREPATH)

buildsignal:
	make -C $(PWD)/$(SIGNALPATH)

buildthreads:
	make -C $(PWD)/$(THREADPATH)

buildsocket:
	make -C $(PWD)/$(SOCKETPATH)

sharedmem:
	make -C $(PWD)/$(SHAREDMEMPATH)

clean:
	make -C $(PWD)/$(STATICLIBPATH) clean
	make -C $(PWD)/$(DYNAMICLIBPATH) clean
	make -C $(PWD)/$(STAT_DYN_LIB_PATH) clean
	make -C $(PWD)/$(FORKPATH) clean
	make -C $(PWD)/$(MUTEXPATH) clean
	make -C $(PWD)/$(PIPEPATH) clean
	make -C $(PWD)/$(SEMAPHOREPATH) clean
	make -C $(PWD)/$(SIGNALPATH) clean
	make -C $(PWD)/$(THREADPATH) clean
	make -C $(PWD)/$(SOCKETPATH) clean
	make -C $(PWD)/$(SHAREDMEMPATH) clean
