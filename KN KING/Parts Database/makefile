inventory: inventory.o readline.o tools.o
	gcc -o inventory inventory.o readline.o tools.o

inventory.o: inventory.c readline.h tools.h
	gcc -c inventory.c

readline.o: readline.c readline.h
	gcc -c readline.c

tools.o: tools.c tools.h readline.h
	gcc -c tools.c