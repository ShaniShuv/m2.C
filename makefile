FLAGS = -Wall 

all: myBank
main.o: main.c myBank.h
	gcc $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
	gcc $(FLAGS) -c myBank.c

myBank: main.o myBank.o myBank.h
	gcc $(FLAGS) -o myBank main.o myBank.o
	
.PHONY: clean all

clean:
	rm -f *.o myBank
