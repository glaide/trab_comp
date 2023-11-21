 # -------------------------------------------------------------------
 #            Arquivo: Makefile
 # -------------------------------------------------------------------
 #              Autor: Bruno Müller Junior
 #               Data: 08/2007
 #      Atualizado em: [09/08/2020, 19h:01m]
 #
 # -------------------------------------------------------------------

$DEPURA=1

compilador: lex.yy.c compilador.tab.c tabelaSimbolos.h pilha.h compilador.o compilador.h
	gcc lex.yy.c compilador.tab.c tabelaSimbolos.c pilha.c compilador.o -o compilador -ll -ly -lc -g

lex.yy.c: compilador.l compilador.h
	flex compilador.l

compilador.tab.c: compilador.y compilador.h
	bison compilador.y -d -v

compilador.o : compilador.h compiladorF.c
	gcc -c compiladorF.c -o compilador.o -g

clean :
	rm -f compilador.tab.* lex.yy.c compilador.o compilador

rodar:
	make clean
	make
	./compilador teste1.pas
