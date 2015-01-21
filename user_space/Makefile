#Makefile to compile all the targets or single target
STATICLIBPATH = ./library/static_lib/
DYNAMICLIBPATH = ./library/dynamic_lib/
STAT_DYN_LIB_PATH = ./library/ 
FORKPATH = ./fork/
MUTEXPATH = ./mutex/
PIPEPATH = ./pipe/
SEMAPHOREPATH = ./semaphore/
SIGNALPATH = ./signals/
THREADPATH = ./threads/
SOCKETPATH = ./socket/
CD = cd
TARG = staticlib dynamiclib all_lib_build buildfork buildmutex buildpipe buildsemaphore buildsignal buildthreads buildsocket 

all: $(TARG)

staticlib: 
	$(CD) $(STATICLIBPATH); make

dynamiclib:
	$(CD) $(DYNAMICLIBPATH); make

all_lib_build:
	$(CD) $(STAT_DYN_LIB_PATH); make

buildfork:
	$(CD) $(FORKPATH); make

buildmutex:
	$(CD) $(MUTEXPATH); make

buildpipe:
	$(CD) $(PIPEPATH); make

buildsemaphore:
	$(CD) $(SEMAPHOREPATH); make

buildsignal:
	$(CD) $(SIGNALPATH); make

buildthreads:
	$(CD) $(THREADPATH); make

buildsocket:
	$(CD) $(SOCKETPATH); make

clean:
	$(CD) $(STATICLIBPATH); make clean
	$(CD) $(DYNAMICLIBPATH); make clean
	$(CD) $(STAT_DYN_LIB_PATH); make clean
	$(CD) $(FORKPATH); make clean
	$(CD) $(MUTEXPATH); make clean
	$(CD) $(PIPEPATH); make clean
	$(CD) $(SEMAPHOREPATH); make clean
	$(CD) $(SIGNALPATH); make clean
	$(CD) $(THREADPATH); make clean
	$(CD) $(SOCKETPATH); make clean
