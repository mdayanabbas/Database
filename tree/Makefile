flags = -Wall -O2 -std=c1x -g
ldflags =

all: tree

tree: tree.o
	gcc ${flags} $^ -o $@ ${ldflags}

tree.o: tree.c
	gcc ${flags} -c $^

run: tree
	tree.exe

clean:
	del /Q *.o tree.exe
