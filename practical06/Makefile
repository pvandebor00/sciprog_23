CC = gcc

install: matrixmult

matrixmult: main.o matmult.o
	$(CC) -o $@ main.o matmult.o

main matmult:
	$(CC) -c $@.c

clean:
	./rm -f *.o
