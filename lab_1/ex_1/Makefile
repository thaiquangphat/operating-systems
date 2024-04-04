calc: calc.o func.o
	gcc -o calc calc.o func.o

calc.o: calc.c
	gcc -c -o calc.o calc.c

func.o: func.c
	gcc -c -o func.o func.c

clean:
	rm -f *.o
	rm calc

all: calc

