all:
	gcc main.c tree.c -I./ -o tree

clean:
	rm *.o

check:
	valgrind --tool=memcheck --leak-check=full ./llist
