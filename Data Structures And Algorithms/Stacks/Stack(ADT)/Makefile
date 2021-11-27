COMPILER=gcc

# Create target binary
client.out: client.o stack.o
			$(COMPILER) -o client.out client.o stack.o
client.o:	client.c stack.h
			$(COMPILER) -c client.c
stack.o: 	stack.c stack.h
			$(COMPILER) -c stack.c

# cleanup object files
clean:
	 	rm -v *.o
# compile and clean
build:
		make && make clean

