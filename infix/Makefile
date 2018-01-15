all: infix
infix: cstack.o stack.o token.o infix.o 
	gcc cstack.c stack.c token.c infix.c -o infix
cstack.o: cstack.c
	gcc -c cstack.c
stack.o: stack.c
	gcc -c stack.c
token.o: token.c
	gcc -c token.c
infix.o: infix.c
	gcc -c infix.c
clean:
	rm -rf *o infix
