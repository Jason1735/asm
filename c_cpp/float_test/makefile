all: ./flo
./flo:./flo.o
	ld -melf_i386 -o $@ $+ -dynamic-linker /lib/ld-linux.so.2 -lc
./flo.o:./flo.s
	as -32 -o $@ $+
clean:
	rm *.o flo
.PHONY:
	all clean
