CC = gcc
CFLAGS = -Wall -Wextra -ggdb -g3
OBJECTS = ast.o grammar.tab.o lex.yy.o main.o preproc.o symtable.o
PROGNAME = test1

all: $(PROGNAME)

$(PROGNAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROGNAME)

ast.o: ast.c ast.h ast_t.h grammar.tab.h
	$(CC) $(CFLAGS) -c ast.c

grammar.tab.o: grammar.tab.c grammar.tab.h ast.h ast_t.h
	$(CC) $(CFLAGS) -c grammar.tab.c

lex.yy.o: lex.yy.c grammar.tab.h
	$(CC) $(CFLAGS) -c lex.yy.c

main.o: main.c ast.h ast_t.h grammar.tab.h symtable.h
	$(CC) $(CFLAGS) -c main.c

preproc.o: preproc.c preproc.h project_t.h
	$(CC) $(CFLAGS) -c preproc.c

symtable.o: symtable.c symtable.h ast.h ast_t.h
	$(CC) $(CFLAGS) -c symtable.c

clean:
	rm -f *.o
	rm -f $(PROGNAME)

check:
	$(CC) $(CFLAGS) -fsyntax-only *.c
