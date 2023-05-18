CC = gcc
CFLAGS = -Wall -Wextra -ggdb -g3 -pipe -I./parser -I./include
OBJECTS = ./lexer/lex.yy.c ./parser/grammar.tab.c o
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

clean:
	rm -f ./obj/*.o
	rm -f $(PROGNAME)
	rm -f ./src/*~
	rm -f ./include/*~

check:
	$(CC) -Wall -Wextra -fsyntax-only ./src/*c
