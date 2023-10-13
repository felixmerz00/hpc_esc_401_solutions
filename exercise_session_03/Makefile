all: cpi get_time

cpi: cpi.c header.h
	cc -c -O3 -o cpi.o cpi.c

get_time: get_time.c header.h
	cc -c -O3 -o get_time.o get_time.c

link: cpi.o get_time.o
	cc cpi.o get_time.o -o program1

cpi_mpi: cpi_mpi.c header.h
	cc -c -O3 -o cpi_mpi.o cpi_mpi.c

link_mpi: cpi_mpi.o get_time.o
	cc cpi_mpi.o get_time.o -o program_mpi

clean:
	rm -f cpi get_time
