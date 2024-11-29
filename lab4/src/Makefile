LEX = flex
CC = gcc
LEX_FILE = ss.l
LEX_OUTPUT = lex.yy.c
LEX_HEADER = lex.yy.h
MAIN_FILE = main.c
EXEC = ss

all: $(EXEC)

$(LEX_OUTPUT) $(LEX_HEADER): $(LEX_FILE)
	$(LEX) $(LEX_FILE)

$(EXEC): $(LEX_OUTPUT) $(MAIN_FILE)
	$(CC) -o $(EXEC) $(LEX_OUTPUT) $(MAIN_FILE) -lfl

clean:
	rm -f $(LEX_OUTPUT) $(LEX_HEADER) $(EXEC)