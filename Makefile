CC = gcc -Wall -std=c99 -fno-inline 
CCOPT = -O2

all: intel-loop

intel-loop: intel-loop.c Makefile
	$(CC) $(CCOPT) -DIACA -c intel-loop.c -o iaca.o
	$(CC) $(CCOPT) --save-temps intel-loop.c -o $@
	objdump --no-show-raw-insn -d $@ > objdump-d.txt

clean:
	rm -rf intel-loop intel-loop.i intel-loop.s iaca.o objdump-d.txt

test: all
	run_all.sh