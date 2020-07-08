TARGET: testdllexe

testdll.o: testdll.c
	gcc -g -c -I . testdll.c -o testdll.o

dll.o: dll.c
	gcc -g -c -I . dll.c -o dll.o

libdll.a: dll.o
	ar rs libdll.a dll.o

testdllexe: dll.o testdll.o
	gcc -g testdll.o -I . -o testdllexe -L . libdll.a

clean:
	rm dll.o
	rm testdll.o
    rm libdll.a
	rm testdllexe
