CC=gcc
CC_OPTIONS=-std=c99

EXE=pa2
OBJ=pa2.o Process.o FIFO.o RR.o STF.o Priority.o

all: $(EXE)
	@echo ""
	@echo "PA2 Built!"
	@echo ""

pa2.o: src/pa2.c
	$(CC) $(CC_OPTIONS) -c src/pa2.c

Process.o: src/Process.c
	$(CC) $(CC_OPTIONS) -c src/Process.c

RR.o: src/algorithms/RR.c
	$(CC) $(CC_OPTIONS) -c src/algorithms/RR.c

FIFO.o: src/algorithms/FIFO.c
	$(CC) $(CC_OPTIONS) -c src/algorithms/FIFO.c

STF.o: src/algorithms/STF.c
	$(CC) $(CC_OPTIONS) -c src/algorithms/STF.c

Priority.o: src/algorithms/Priority.c
	$(CC) $(CC_OPTIONS) -c src/algorithms/Priority.c

pa2: pa2.o Process.o RR.o Priority.o STF.o FIFO.o
	$(CC) $(CC_OPTIONS) pa2.o Process.o RR.o Priority.o STF.o FIFO.o -o pa2

run:
	@make all

clean:
	rm -f $(EXE) $(OBJ)
