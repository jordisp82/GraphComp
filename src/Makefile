CC = gcc
CFLAGS = -Wall -Wextra -ggdb -g3 -pipe
OBJECTS = ast.o grammar.tab.o lex.yy.o main.o preproc.o semantic.o func_def.o decl_specs.o declarator.o dir_declr.o
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

main.o: main.c ast.h ast_t.h grammar.tab.h semantic.h
	$(CC) $(CFLAGS) -c main.c

preproc.o: preproc.c preproc.h project_t.h
	$(CC) $(CFLAGS) -c preproc.c

semantic.o: semantic.c semantic.h ast_t.h ast.h grammar.tab.h nonterms.h func_def.h
	$(CC) $(CFLAGS) -c semantic.c

func_def.o: func_def.c func_def.h nonterms.h ast.h ast_t.h grammar.tab.h decl_specs.h declarator.h
	$(CC) $(CFLAGS) -c func_def.c

decl_specs.o: decl_specs.c decl_specs.h ast.h ast_t.h grammar.tab.h nonterms.h
	$(CC) $(CFLAGS) -c decl_specs.c

declarator.o: declarator.c declarator.h nonterms.h ast.h ast_t.h grammar.tab.h dir_declr.h
	$(CC) $(CFLAGS) -c declarator.c

dir_declr.o: dir_declr.c dir_declr.h nonterms.h ast.h ast_t.h grammar.tab.h declarator.h decl_specs.h
	$(CC) $(CFLAGS) -c dir_declr.c

clean:
	rm -f *.o
	rm -f $(PROGNAME)

check:
	$(CC) -Wall -Wextra -fsyntax-only *.c
