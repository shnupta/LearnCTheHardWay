CFLAGS=-Wall -g -DNDEGUB

all:
	cc -c libex29.c -o libex29.o
	cc -shared -o libex29.so libex29.o
	cc -ldl ex29.c -o ex29

clean:
	rm -rf ex29 libex29.o libex29.so