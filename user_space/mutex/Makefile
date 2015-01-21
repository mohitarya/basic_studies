CC = gcc
RM = rm -rf
SOURCE = mutex.c
CFLAG = -lpthread

mutex: $(SOURCE)
	$(CC) -o $@ $? $(CFLAG)

clean:
	$(RM) mutex
