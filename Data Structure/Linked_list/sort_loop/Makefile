output: main.o insert_sorted.o find_loop.o create_loop.o print_list.o
	gcc main.o insert_sorted.o find_loop.o create_loop.o print_list.o -o output

main.o: main.c
	gcc -c main.c

insert_sorted.o: insert_sorted.c
	gcc -c insert_sorted.c

find_loop.o: find_loop.c
	gcc -c find_loop.c

create_loop.o: create_loop.c
	gcc -c create_loop.c

print_list.o: print_list.c
	gcc -c print_list.c

clean: 
	rm *.o output

