main : main.c
	gcc -o main main.c

table.o : table.c
	gcc -c table.c

boyer_moore.o : boyer_moore.c
	gcc -c boyer_moore.c

test : test.c table.o boyer_moore.o
	gcc -o test table.o boyer_moore.o test.c

clean :
	rm -f main table.o boyer_moore.o test
run : main
	./main

