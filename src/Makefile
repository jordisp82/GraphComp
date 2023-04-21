CC = gcc
CFLAGS = -Wall -Wextra -ggdb -g3
OBJECTS = ast.o grammar.tab.o lex.yy.o main.o preproc.o semantic.o func_def.o declaration.o decl_aux.o decl_specs.o enums.o struct_union.o
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

semantic.o: semantic.c semantic.h ast_t.h func_def.h declaration.h
	$(CC) $(CFLAGS) -c semantic.c

func_def.o: func_def.c func_def.h ast_t.h
	$(CC) $(CFLAGS) -c func_def.c

declaration.o: declaration.c declaration.h ast_t.h declaration_t.h decl_specs.h
	$(CC) $(CFLAGS) -c declaration.c

decl_aux.o: decl_aux.c decl_aux.h declaration_t.h
	$(CC) $(CFLAGS) -c decl_aux.c

decl_specs.o: decl_specs.c decl_specs.h ast_t.h decl_aux.h
	$(CC) $(CFLAGS) -c decl_specs.c

enums.o: enums.c enums.h ast_t.h ast.h declaration_t.h
	$(CC) $(CFLAGS) -c enums.c

struct_union.o: struct_union.c struct_union.h ast_t.h ast.h
	$(CC) $(CFLAGS) -c struct_union.c

clean:
	rm -f *.o
	rm -f $(PROGNAME)

check:
	$(CC) $(CFLAGS) -fsyntax-only *.c
