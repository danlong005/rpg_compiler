
all: tidy
	bison -vd parser.y
	flex lexer.l
	gcc -o rpgcc parser.tab.c

clean: tidy
	rm -f rpgcc
	rm -f output/*
	rm -rf a.out 

tidy: 
	rm -f parser.tab.* parser.output lex.yy.c
