CC = gcc
CFLAGS = -Wall -Wextra -ggdb -g3 -pipe
OBJECTS = ast.o grammar.tab.o lex.yy.o main.o preproc.o semantic.o func_def.o decl_specs.o declarator.o dir_declr.o declaration.o prim_expr.o postfix_expr.o unary_expr.o cast_expr.o mult_expr.o add_expr.o bitw_expr.o rel_expr.o equal_expr.o bit_and_expr.o bit_xor_expr.o bit_or_expr.o logic_and_expr.o logic_or_expr.o cond_expr.o ass_expr.o expression.o compound_stmt.o statement.o abs_declr.o dir_abs_declr.o
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

semantic.o: semantic.c semantic.h ast_t.h ast.h grammar.tab.h nonterms.h func_def.h declaration.h
	$(CC) $(CFLAGS) -c semantic.c

func_def.o: func_def.c func_def.h nonterms.h ast.h ast_t.h grammar.tab.h decl_specs.h declarator.h
	$(CC) $(CFLAGS) -c func_def.c

decl_specs.o: decl_specs.c decl_specs.h ast.h ast_t.h grammar.tab.h nonterms.h
	$(CC) $(CFLAGS) -c decl_specs.c

declarator.o: declarator.c declarator.h nonterms.h ast.h ast_t.h grammar.tab.h dir_declr.h
	$(CC) $(CFLAGS) -c declarator.c

dir_declr.o: dir_declr.c dir_declr.h nonterms.h ast.h ast_t.h grammar.tab.h declarator.h decl_specs.h
	$(CC) $(CFLAGS) -c dir_declr.c

declaration.o: declaration.c declaration.h ast.h ast_t.h nonterms.h grammar.tab.h decl_specs.h declarator.h
	$(CC) $(CFLAGS) -c declaration.c

prim_expr.o: prim_expr.c prim_expr.h nonterms.h ast.h ast_t.h grammar.tab.h
	$(CC) $(CFLAGS) -c prim_expr.c

postfix_expr.o: postfix_expr.c postfix_expr.h nonterms.h ast.h ast_t.h grammar.tab.h prim_expr.h
	$(CC) $(CFLAGS) -c postfix_expr.c

unary_expr.o: unary_expr.c unary_expr.h nonterms.h ast.h ast_t.h grammar.tab.h postfix_expr.h cast_expr.h
	$(CC) $(CFLAGS) -c unary_expr.c

cast_expr.o: cast_expr.c cast_expr.h nonterms.h ast.h ast_t.h grammar.tab.h unary_expr.h
	$(CC) $(CFLAGS) -c cast_expr.c

mult_expr.o: mult_expr.c mult_expr.h nonterms.h ast.h ast_t.h grammar.tab.h cast_expr.h
	$(CC) $(CFLAGS) -c mult_expr.c

add_expr.o: add_expr.c add_expr.h nonterms.h ast.h ast_t.h grammar.tab.h mult_expr.h
	$(CC) $(CFLAGS) -c add_expr.c

bitw_expr.o: bitw_expr.c bitw_expr.h nonterms.h ast.h ast_t.h grammar.tab.h add_expr.h
	$(CC) $(CFLAGS) -c bitw_expr.c

rel_expr.o: rel_expr.c rel_expr.h nonterms.h ast.h ast_t.h grammar.tab.h bitw_expr.h
	$(CC) $(CFLAGS) -c rel_expr.c

equal_expr.o: equal_expr.c equal_expr.h nonterms.h ast.h ast_t.h grammar.tab.h rel_expr.h
	$(CC) $(CFLAGS) -c equal_expr.c

bit_and_expr.o: bit_and_expr.c bit_and_expr.h nonterms.h ast.h ast_t.h grammar.tab.h equal_expr.h
	$(CC) $(CFLAGS) -c bit_and_expr.c

bit_xor_expr.o: bit_xor_expr.c bit_xor_expr.h nonterms.h ast.h ast_t.h grammar.tab.h bit_and_expr.h
	$(CC) $(CFLAGS) -c bit_xor_expr.c

bit_or_expr.o: bit_or_expr.c bit_or_expr.h nonterms.h ast.h ast_t.h grammar.tab.h bit_xor_expr.h
	$(CC) $(CFLAGS) -c bit_or_expr.c

logic_and_expr.o: logic_and_expr.c logic_and_expr.h nonterms.h ast.h ast_t.h grammar.tab.h bit_or_expr.h
	$(CC) $(CFLAGS) -c logic_and_expr.c

logic_or_expr.o: logic_or_expr.c logic_or_expr.h nonterms.h ast.h ast_t.h grammar.tab.h logic_and_expr.h
	$(CC) $(CFLAGS) -c logic_or_expr.c

cond_expr.o: cond_expr.c cond_expr.h nonterms.h ast.h ast_t.h grammar.tab.h logic_or_expr.h
	$(CC) $(CFLAGS) -c cond_expr.c

ass_expr.o: ass_expr.c ass_expr.h nonterms.h ast.h ast_t.h grammar.tab.h cond_expr.h unary_expr.h
	$(CC) $(CFLAGS) -c ass_expr.c

expression.o: expression.c expression.h nonterms.h ast.h ast_t.h grammar.tab.h ass_expr.h
	$(CC) $(CFLAGS) -c expression.c

compound_stmt.o: compound_stmt.c compound_stmt.h nonterms.h ast.h ast_t.h grammar.tab.h declaration.h
	$(CC) $(CFLAGS) -c compound_stmt.c

statement.o: statement.c statement.h nonterms.h ast.h ast_t.h grammar.tab.h compound_stmt.h expression.h cond_expr.h
	$(CC) $(CFLAGS) -c statement.c

abs_declr.o: abs_declr.c abs_declr.h nonterms.h ast.h ast_t.h grammar.tab.h
	$(CC) $(CFLAGS) -c abs_declr.c

dir_abs_declr.o: dir_abs_declr.c dir_abs_declr.h nonterms.h ast.h ast_t.h grammar.tab.h abs_declr.h ass_expr.h
	$(CC) $(CFLAGS) -c dir_abs_declr.c

clean:
	rm -f *.o
	rm -f $(PROGNAME)

check:
	$(CC) -Wall -Wextra -fsyntax-only *.c
