CC = gcc
FLAGS = -Wall -g
VALGRIND = valgrind --leak-check=full --error-exitcode=1
all:graph

graph:main.o algo.o
	$(CC) $(FLAGS)  -o graph main.o algo.o
algo: algo.c graph.h
	$(CC) $(FLAGS) -valgrind  --leak-check=yes -c algo.c
main: main.c graph.h
	$(CC) $(FLAGS) -valgrind  --leak-check=yes -c main.c




.PHONY: clean all
clean:
	rm -f *.o graph

