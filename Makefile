all: main

main: stack.o dlist.o queue.o main.c
	gcc -o main -g main.c queue.o dlist.o stack.o -lm

stack.o: stack.c stack.h
	gcc -c -Wall -Wextra -Werror -g stack.c

queue.o: queue.c queue.h
	gcc -c -Wall -Wextra -Werror -g queue.c

dlist.o: dlist.c dlist.h
	gcc -c -Wall -Wextra -Werror -g dlist.c

clean:
	rm *.o
