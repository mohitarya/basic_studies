#This make file will build executable file for the thread program

CC = gcc
TARGET = thread
SOURCE = thread.c
LIB = -lpthread
RM = rm -rf

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) -o $(TARGET) $(SOURCE) $(LIB)

clean:
	$(RM) $(TARGET)
