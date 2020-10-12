# Makefile for linux asm/c/c++

BIN = ./bin
SRC_S = ./src_s
OBJ = ./obj

TARGET = main
BINARY = ${BIN}/${TARGET}

SOURCE_S = $(wildcard ${SRC_S}/*.s)

OBJECT = $(patsubst %.s, ${OBJ}/%.o, $(notdir ${SOURCE_S}))

AS = as
LD = ld

ASFLAGS = -g -32
LDFLAGS = -g -melf_i386 -dynamic-linker /lib/ld-linux.so.2
LIBS = -lc

all: $(BINARY)

$(BINARY): $(OBJECT)
	@$(LD) $(LDFLAGS) $+ -o $@ $(LIBS)

${OBJ}/%.o: ${SRC_S}/%.s
	@$(AS) $(ASFLAGS) -o $@ $+

clean:
	@$(RM) $(OBJECT) $(BINARY) *~
.PHONY:
	all clean
