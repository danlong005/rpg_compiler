CC=gcc

all:
	bison -t -v -d rpg.y
	flex rpg.l
	gcc -o rpg rpg.tab.c lex.yy.c

clean:
	rm rpg rpg.tab.c lex.yy.c rpg.tab.h rpg.output
