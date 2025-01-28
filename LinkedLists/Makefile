test : ll.o test.c
	gcc -Wall -fsanitize=address -o test ll.o test.c

ll.o : ll.c
	gcc -Wall -fsanitize=address -c ll.c

clean :
	rm -f test ll.o
