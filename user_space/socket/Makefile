CLIENTPATH = ./client/
SERVERPATH = ./server/

CD = cd

all: buildclient buildserver

buildclient:
	$(CD) $(CLIENTPATH); make

buildserver:
	$(CD) $(SERVERPATH); make

clean:
	$(CD) $(CLIENTPATH); make clean
	$(CD) $(SERVERPATH); make clean
	
	
