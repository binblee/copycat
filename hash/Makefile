COMPILE_OPTIONS = -Wpointer-sign -Wformat
testhash: main.o hash.o
	gcc -o testhash main.o hash.o
main.o: main.c
	gcc $(COMPILE_OPTIONS) -c main.c

hash.o: hash.c
	gcc $(COMPILE_OPTIONS) -c hash.c

clean:
	rm *.o
	rm testhash