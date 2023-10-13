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

sum: sum.c header.h
	cc -c -O3 -o sum.o sum.c

link_sum: sum.o get_time.o
	cc sum.o get_time.o -o program_sum

sum_O0: sum.c header.h
	cc -c -O0 -o sum_O0.o sum.c

link_sum_O0: sum_O0.o get_time.o
	cc sum_O0.o get_time.o -o program_sum_O0

sum_O1: sum.c header.h
	cc -c -O1 -o sum_O1.o sum.c

link_sum_O1: sum_O1.o get_time.o
	cc sum_O1.o get_time.o -o program_sum_O1

sum_O2: sum.c header.h
	cc -c -O2 -o sum_O2.o sum.c

link_sum_O2: sum_O2.o get_time.o
	cc sum_O2.o get_time.o -o program_sum_O2

clean:
	rm -f cpi get_time
