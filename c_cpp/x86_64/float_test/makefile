all: ./flo
./flo:./flo.o
	ld -melf_x86_64 -o $@ $+ -dynamic-linker /lib64/ld-linux-x86-64.so.2 -lc
./flo.o:./flo.s
	as -o $@ $+
clean:
	rm *.o flo
.PHONY:
	all clean
