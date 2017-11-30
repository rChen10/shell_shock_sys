all : main.c shell.c shell.h
	gcc main.c -o shell_shock

test : shell.c shell.h
	gcc shell.c
	./a.out
	rm ./a.out

run: all
	./shell_shock
