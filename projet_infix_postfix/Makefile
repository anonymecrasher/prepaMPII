main : main.c pile.o
	gcc -o main pile.o main.c

pile.o : pile.c
	gcc -c pile.c

clean :
	rm -f main pile.o

mainocaml : main.ml
	ocamlc main.ml -o mainocaml

run : main mainocaml
	./main | ./mainocaml
