main : main.c pile.o sizeable_table.o queue.o
	gcc -o main pile.o queue.o sizeable_table.o main.c

pile.o : pile.c
	gcc -c pile.c

queue.o : queue.c
	gcc -c queue.c

sizeable_table.o : sizeable_table.c
	gcc -c sizeable_table.c

clean :
	rm -f main pile.o queue.o sizeable_table.o

mainocaml : main.ml
	ocamlc main.ml -o mainocaml

run : main mainocaml
	./main | ./mainocaml
