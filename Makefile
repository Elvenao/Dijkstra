CC:=cc
CFLAGS:=-Wall -Wextra -std=c99 -pedantic -g -I./
LIBS:=
BIN:=main

SRC:=main.c Dijkstra.c list.c

all:
	${CC} ${CFLAGS} ${SRC} ${LIBS} -o ${BIN}

.PHONY: clean
clean:
	@rm -rfv ${BIN}
