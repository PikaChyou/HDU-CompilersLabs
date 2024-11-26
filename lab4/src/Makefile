LEX = flex
CC = gcc
LEX_FILE = ss.l
LEX_OUTPUT = lex.yy.c
EXEC = ss

all: $(EXEC)

$(LEX_OUTPUT): $(LEX_FILE)
	$(LEX) $(LEX_FILE)

$(EXEC): $(LEX_OUTPUT)
	$(CC) -o $(EXEC) $(LEX_OUTPUT) -ll

clean:
	rm -f $(LEX_OUTPUT) $(EXEC)

.PHONY: all clean