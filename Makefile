all: dlist.o queue.o stack.o main

main: stack.o queue.o main.c dlist.o
	gcc -o main -g main.c stack.o queue.o dlist.o -lm

stack.o: lists/stack.c lists/stack.h 
	gcc -c -Wall -Wextra -Werror -g lists/stack.c

queue.o: lists/queue.c lists/queue.h
	gcc -c -Wall -Wextra -Werror -g lists/queue.c

dlist.o: lists/dlist/dlist.c lists/dlist/dlist.h
	gcc -c -c -Wall -Wextra -Werror -g lists/dlist/dlist.c

clean:
	rm *.o