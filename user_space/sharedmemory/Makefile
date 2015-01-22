CC = gcc
RM = rm -rf

all: consumer producer

consumer: consumer.c
	$(CC) -o $@ $?

producer: producer.c
	$(CC) -o $@ $?

clean:
	$(RM) consumer producer
