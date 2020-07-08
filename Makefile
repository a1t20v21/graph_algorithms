TARGET: testgraphexe

graph/testgraph.o: graph/testgraph.c
	gcc -g -c -I . graph/testgraph.c -o graph/testgraph.o

dll/dll.o: dll/dll.c
	gcc -g -c -I . dll/dll.c -o dll/dll.o

graph/graph.o: graph/graph.c
	gcc -g -c -I . graph/graph.c -o graph/graph.o

graph/libgraph.a: dll/dll.o graph/graph.o
	ar rs graph/libgraph.a dll/dll.o graph/graph.o

testgraphexe: graph/libgraph.a graph/testgraph.o
	gcc -g graph/testgraph.o -I . -o testgraphexe -L . graph/libgraph.a

clean:
	rm dll/dll.o
	rm graph/graph.o
	rm graph/testgraph.o
	rm graph/libgraph.a
	rm testgraphexe
