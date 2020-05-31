all: main

main: stack.o queue.o main.c
	gcc -o main -g main.c stack.o queue.o -lm

stack.o: stack.c headers/stack.h
	gcc -c -Wall -Wextra -Werror -g stack.c

queue.o: queue.c headers/queue.h
	gcc -c -Wall -Wextra -Werror -g queue.c

clean:
	rm *.o