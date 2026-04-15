CC = gcc
FLEX = flex
CFLAGS = -Wall -Wextra

TARGET = numerics_lexer
SOURCES = main.c lex.yy.c
OBJECTS = main.o lex.yy.o
HEADER = tokens.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c $(HEADER)
	$(CC) $(CFLAGS) -c main.c

lex.yy.c: numerics.l $(HEADER)
	$(FLEX) numerics.l

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c

clean:
	rm -f $(OBJECTS) lex.yy.c $(TARGET)

.PHONY: all clean
