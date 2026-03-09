all:
	cd ./a1 && flex lexer.l
	gcc ./a1/lex.yy.c -o ./a1/lexer
	./a1/lexer
