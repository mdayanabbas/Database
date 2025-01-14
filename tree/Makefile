flags = -Wall -O2 -std=c1x
ldflags =

all: tree

tree: tree.o
	gcc ${flags} $^ -o $@ ${ldflags}

tree.o: tree.c
	gcc ${flags} -c $^

run: tree
	./tree

clean:
	del /Q *.o tree
