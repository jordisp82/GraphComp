CC = gcc
CFLAGS = -Wall -Wextra -ggdb -g3 -pipe -I./parser -I./include
OBJECTS = ./lexer/lex.yy.c ./parser/grammar.tab.c ./obj/main.o ./obj/ast.o ./obj/semantic.o ./obj/func_def.o ./obj/compound_stmt.o ./obj/statement.o ./obj/declaration.o ./obj/decl_specs.o ./obj/declarator.o
PROGNAME = test1

all: $(PROGNAME)

$(PROGNAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROGNAME)

./lexer/lex.yy.c: ./lexer/scanner.lex
	cd lexer; flex scanner.lex
	cd ..

./parser/grammar.tab.c: ./parser/grammar.y
	cd parser; bison -d grammar.y
	cd ..

./obj/main.o: ./src/main.c ./include/ast.h ./include/ast_t.h ./parser/grammar.tab.h ./include/semantic.h
	$(CC) $(CFLAGS) -c ./src/main.c -o ./obj/main.o

./obj/ast.o: ./src/ast.c ./include/ast.h ./parser/grammar.tab.h ./include/ast_t.h
	$(CC) $(CFLAGS) -c ./src/ast.c -o ./obj/ast.o

./obj/semantic.o: ./src/semantic.c ./include/semantic.h ./include/ast.h ./include/ast_t.h ./include/sem_t.h ./parser/grammar.tab.h ./include/func_def.h ./include/declaration.h
	$(CC) $(CFLAGS) -c ./src/semantic.c -o ./obj/semantic.o

./obj/func_def.o: ./src/func_def.c ./include/func_def.h ./include/ast.h ./include/ast_t.h ./include/sem_t.h ./parser/grammar.tab.h ./include/compound_stmt.h ./include/decl_specs.h ./include/declarator.h
	$(CC) $(CFLAGS) -c ./src/func_def.c -o ./obj/func_def.o

./obj/compound_stmt.o: ./src/compound_stmt.c ./include/compound_stmt.h ./include/ast.h ./include/ast_t.h ./include/sem_t.h ./parser/grammar.tab.h ./include/statement.h ./include/declaration.h
	$(CC) $(CFLAGS) -c ./src/compound_stmt.c -o ./obj/compound_stmt.o

./obj/statement.o: ./src/statement.c ./include/statement.h ./include/ast.h ./include/ast_t.h ./include/sem_t.h ./parser/grammar.tab.h ./include/compound_stmt.h ./include/declaration.h
	$(CC) $(CFLAGS) -c ./src/statement.c -o ./obj/statement.o

./obj/declaration.o: ./src/declaration.c ./include/declaration.h ./include/ast.h ./include/ast_t.h ./include/sem_t.h ./parser/grammar.tab.h ./include/decl_specs.h
	$(CC) $(CFLAGS) -c ./src/declaration.c -o ./obj/declaration.o

./obj/decl_specs.o: ./src/decl_specs.c ./include/decl_specs.h ./include/ast.h ./include/ast_t.h ./include/sem_t.h ./parser/grammar.tab.h
	$(CC) $(CFLAGS) -c ./src/decl_specs.c -o ./obj/decl_specs.o

./obj/declarator.o: ./src/declarator.c ./include/declarator.h  ./include/ast.h ./include/ast_t.h ./include/sem_t.h ./parser/grammar.tab.h
	$(CC) $(CFLAGS) -c ./src/declarator.c -o ./obj/declarator.o

clean:
	rm -f ./obj/*.o
	rm -f $(PROGNAME)
	rm -f ./src/*~
	rm -f ./include/*~

check:
	$(CC) -Wall -Wextra -fsyntax-only ./src/*c
