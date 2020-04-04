#main.o: main.c
#	gcc -c main.c
#	gcc main.o -L. -lcalculator -o calculator
all: calculator main
calculator:
	gcc -c calculator.c
	ar rcs libcalculator.a calculator.o
main:
	gcc -c main.c -o main.o
	gcc main.o -L. -lcalculator -o calculator
clean:
	rm -f main.o calculator
	rm -f libcalculator.a calculator.o
