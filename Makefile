CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++14 -pedantic-errors $(DEBUG)
LFLAGS = -Wall $(DEBUG)

compile: proj1.out

proj1.out: main.o proj1.o
	$(CC) $(LFLAGS) -o proj1.out main.o proj1.o

main.o: main.cpp proj1.h
	$(CC) $(CFLAGS) main.cpp

proj1.o: proj1.cpp proj1.h
	$(CC) $(CFLAGS) proj1.cpp

run: proj1.out
	./proj1.out -a -v 5 2 3 1 9 -e 97
	./proj1.out -v 5 2 3 1 9 -e 97 -a
	./proj1.out -e 97 -v 5 2 3 1 9 -b
	./proj1.out -v 5 2 3 1 9 -b -e 97

clean:
	rm proj1.out
	rm *.o
