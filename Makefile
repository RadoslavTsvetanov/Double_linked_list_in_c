all: tests.exe

two_linked_list.o: two_linked_list.h two_linked_list.c
	gcc -c two_linked_list.c -o two_linked_list.o

tests.exe: tests.c two_linked_list.o
	gcc tests.c two_linked_list.o -o tests.exe

clean:
	del *.o *.exe