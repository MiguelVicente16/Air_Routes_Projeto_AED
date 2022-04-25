#
# Makefile for heap example - process scheduler
#

CC=gcc
TARGET=backbone
CFLAGS= -Wall -std=c99 -O3
LIBS= -lm

SRCFILES= main.c Abstratos.c Matriz.c Modos.c Graph.c ManipularMST.c EncontrarMST.c
INCFILES= Abstratos.h Matriz.h Modos.h Graph.h ManipularMST.h EncontrarMST.h
OBJFILES= main.o Abstratos.o Matriz.o Modos.o Graph.o ManipularMST.o EncontrarMST.o

default: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJFILES) core.* #*

Abstratos.o: Abstratos.h Abstratos.c

Matriz.o: Matriz.c Matriz.h

Graph.o: Graph.c Graph.h

ManipularMST.o: ManipularMST.h ManipularMST.c

EncontrarMST.o: EncontrarMST.h EncontrarMST.c

Modos.o: Modos.c Modos.h Abstratos.h Matriz.h Graph.h ManipularMST.h EncontrarMST.h

main.o: main.c Modos.h Abstratos.h Matriz.h Graph.h ManipularMST.h EncontrarMST.h

FILES1 = $(shell ls *.routes)

VALG = valgrind --leak-check=full --show-leak-kinds=all

run1:
		for F in ${FILES1}; do ./backbone $${F}; done;

vrun1:
		for F in ${FILES1}; do ${VALG} ./backbone $${F}; done;
