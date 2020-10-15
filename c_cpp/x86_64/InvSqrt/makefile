# Makefile for linux asm/c/c++

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

CFLAGS = -g -Wall -O2
ASFLAGS = -gstabs
LDFLAGS = -melf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2
LIBS = /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/7/crtbegin.o /usr/lib/gcc/x86_64-linux-gnu/7/crtend.o /usr/lib/x86_64-linux-gnu/crtn.o -L/usr/lib/gcc/x86_64-linux-gnu/7 -lstdc++ -lc -lm

all: $(BINARY)

$(BINARY): $(OBJECT)
	$(LD) $(LDFLAGS) $+ -o $@ $(LIBS)

${OBJ}/%.o: ${SRC_C}/%.c
	$(CC) $(CFLAGS) -o $@ -c $+

${OBJ}/%.o: ${SRC_CPP}/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $+

${OBJ}/%.o: ${SRC_S}/%.s
	$(AS) $(ASFLAGS) -o $@ $+

clean:
	$(RM) $(OBJECT) $(BINARY) *~
.PHONY:
	all clean
