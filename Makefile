CC=g++

all: main

main:  
	$(CC) -o parser parser.cpp

clean:
	rm -rf *.o *.out parser


