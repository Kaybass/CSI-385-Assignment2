CC=gcc
CC_OPTIONS=-std=c99

EXE=pa2
OBJ=pa2.o Process.o FIFO.o RR.o STF.o Priority.o

all: $(EXE)
	@echo ""
	@echo "PA2 Built!"
	@echo ""

pa2.o: pa2.c
	$(CC) $(CC_OPTIONS) -c pa2.c

Process.o: Process.c
	$(CC) $(CC_OPTIONS) -c Process.c

RR.o: algorithms/RR.c
	$(CC) $(CC_OPTIONS) -c algorithms/RR.c

FIFO.o: algorithms/FIFO.c
	$(CC) $(CC_OPTIONS) -c algorithms/FIFO.c

STF.o: algorithms/STF.c
	$(CC) $(CC_OPTIONS) -c algorithms/STF.c

Priority.o: algorithms/Priority.c
	$(CC) $(CC_OPTIONS) -c algorithms/Priority.c

pa2: pa2.o Process.o RR.o Priority.o STF.o FIFO.o
	$(CC) $(CC_OPTIONS) pa2.o Process.o RR.o Priority.o STF.o FIFO.o -o pa2

run:
	@make all

clean:
	rm -f $(EXE) $(OBJ)
