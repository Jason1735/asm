# Makefile for linux as

BIN = ./bin
SRC_C = ./src_c
SRC_CPP = ./src_cpp
SRC_S = ./src_s
OBJ = ./obj
INC = ./inc

TARGET = main
BINARY = ${BIN}/${TARGET}

SOURCE_C = $(wildcard ${SRC_C}/*.c)
SOURCE_CPP = $(wildcard ${SRC_CPP}/*.cpp)
SOURCE_S = $(wildcard ${SRC_S}/*.s)

OBJECT = $(patsubst %.c, ${OBJ}/%.o, $(notdir ${SOURCE_C}))
OBJECT += $(patsubst %.cpp, ${OBJ}/%.o, $(notdir ${SOURCE_CPP}))
OBJECT += $(patsubst %.s, ${OBJ}/%.o, $(notdir ${SOURCE_S}))

AS = as
LD = ld

CFLAGS = -g -Wall -m32 -O2
ASFLAGS = -g -32
LDFLAGS = -g -melf_i386 -dynamic-linker /lib/ld-linux.so.2
LIBS = /usr/lib32/crt1.o /usr/lib32/crti.o /usr/lib/gcc/x86_64-linux-gnu/7/32/crtbegin.o /usr/lib/gcc/x86_64-linux-gnu/7/32/crtend.o /usr/lib32/crtn.o -L/usr/lib/gcc/x86_64-linux-gnu/7/32 -lstdc++ -lc -lm

all: $(BINARY)

$(BINARY): $(OBJECT)
	@$(LD) $(LDFLAGS) $+ -o $@ $(LIBS)

${OBJ}/%.o: ${SRC_C}/%.c
	@$(CC) $(CFLAGS) -o $@ -c $+

${OBJ}/%.o: ${SRC_CPP}/%.cpp
	@$(CC) $(CFLAGS) -o $@ -c $+

${OBJ}/%.o: ${SRC_S}/%.s
	@$(AS) $(ASFLAGS) -o $@ $+

clean:
	@$(RM) $(OBJECT) $(BINARY) *~
.PHONY:
	all clean
