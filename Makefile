all: cg2d exemplo1

cg2d:
	gcc -c cg2d.c

exemplo1: cg2d.o 
	gcc exemplo_1.c -o exemplo_1 cg2d.o -lm -lX11
	gcc Atividade1.c -o Atividade1 cg2d.o -lm -lX11
	gcc Atividade2.c -o Atividade2 cg2d.o -lm -lX11
