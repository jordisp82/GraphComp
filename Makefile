CC = gcc
CFLAGS = -Wall -Wextra -ggdb -g3 -pipe -I./parser -I./include
OBJECTS = ./lexer/lex.yy.c ./parser/grammar.tab.c ./obj/main.o ./obj/ast.o ./obj/semantic.o
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

./obj/main.o: ./src/main.c ./include/ast.h
	$(CC) $(CFLAGS) -c ./src/main.c -o ./obj/main.o

./obj/ast.o: ./src/ast.c ./parser/grammar.tab.h ./include/ast_t.h
	$(CC) $(CFLAGS) -c ./src/ast.c -o ./obj/ast.o

./obj/semantic.o: ./src/semantic.c ./include/semantic.h ./include/ast.h ./include/ast_t.h ./include/sem_t.h ./parser/grammar.tab.h
	$(CC) $(CFLAGS) -c ./src/semantic.c -o ./obj/semantic.o

clean:
	rm -f ./obj/*.o
	rm -f $(PROGNAME)

check:
	$(CC) -Wall -Wextra -fsyntax-only ./src/*c
