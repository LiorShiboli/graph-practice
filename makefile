CC = gcc
FLAGS = -Wall -g
VALGRIND = valgrind --leak-check=full --error-exitcode=1
all:graph

graph:main.o algo.o edges.o node.o
	$(CC) $(FLAGS)  -o graph main.o algo.o edges.o node.o
algo: algo.c graph.h
	$(CC) $(FLAGS) -valgrind  --leak-check=yes -c algo.c
main: main.c graph.h
	$(CC) $(FLAGS) -valgrind  --leak-check=yes -c main.c
edges: edge.c graph.h
	$(CC) $(FLAGS) -valgrind  --leak-check=yes -c edges.c
node: node.c graph.h edge.h
	$(CC) $(FLAGS) -valgrind  --leak-check=yes -c node.c



.PHONY: clean all
clean:
	rm -f *.o graph

