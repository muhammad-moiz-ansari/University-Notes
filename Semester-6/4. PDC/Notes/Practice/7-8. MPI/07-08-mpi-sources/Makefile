
CC=mpicc
CFLAGS=-O3 -fopenmp -mavx2 -mfma -march=native

all:
	for f in *.c; do $(CC) $(CFLAGS) $$f -o $${f%.c}; done

clean:
	rm -f p*
