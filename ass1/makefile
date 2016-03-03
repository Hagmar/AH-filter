CC=g++

all: ahencode ahdecode

ahencode: ahencode.cpp ahencode.h filter.o
	$(CC) -o ahencode ahencode.cpp

ahdecode: ahdecode.cpp ahdecode.h filter.o
	$(CC) -o ahdecode ahdecode.cpp

filter.o: filter.cpp filter.h
	$(CC) -c filter.cpp

clean:
	rm *.o
