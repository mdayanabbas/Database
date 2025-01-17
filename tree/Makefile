CC = gcc
CFLAGS = -O2 -Wall -std=c1x
LDFLAGS = -lws2_32

all: cache22.exe tree.exe

cache22.exe: cache22.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

cache22.o: cache22.c
	$(CC) $(CFLAGS) -c $^

tree.exe: tree.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

tree.o: tree.c
	$(CC) $(CFLAGS) -c $^

run-cache22: cache22.exe
	./cache22.exe 8080

run-tree: tree.exe
	./tree.exe

clean:
	del /Q *.o cache22.exe tree.exe



# mingw32-make clean
# mingw32-make
# mingw32-make run