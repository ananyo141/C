justify: justifyText.o word.o line.o
	gcc -o justify justifyText.o word.o line.o

justifyText.o: justifyText.c line.h word.h
	gcc -c justifyText.c

line.o: line.c line.h
	gcc -c line.c

word.o: word.c word.h
	gcc -c word.c