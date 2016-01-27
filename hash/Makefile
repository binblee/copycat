COMPILE_OPTIONS = -Wpointer-sign -Wformat

build: testhash

testhash: main.o hash.o
	gcc -o testhash main.o hash.o

main.o: main.c
	gcc $(COMPILE_OPTIONS) -c main.c

hash.o: hash.c hash.h
	gcc $(COMPILE_OPTIONS) -c hash.c

test: build
	./testhash

clean: build
	rm *.o
	rm testhash