#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "token.h"
#include "stack.h"
#include <limits.h>
int reset=0;
int readline(char *arr, int len) {
	int i = 0;
	int ch;
	while((ch = getchar()) != '\n' && i < len - 1) {
		arr[i] = ch;
		i++;
	}
	arr[i] = '\0';
	return i;
}

int precedence(char op) {
	if(op== '(')
		return 4;
	if(op == '*' || op == '/' || op == '%')
		return 3;
	if(op == '+' || op == '-')
		return 2;
	if(op== '(' || op== ')')
		return 1;
	return 0;
}
int ctop(cstack *cs) {
	char x = cpop(cs);
	cpush(cs, x);
	return x++;
}
int operation(int y , int x , char op) {
	switch(op) {
		case '+':
			return (y + x);
					
		case '-':
			return (y - x);
					
		case '*':
			return (y * x);
				
		case '/':
			return ( y / x);
					
		case '%':
			return ( y % x);
	}	
				
			
}
int infixeval(char *str) {
	cstack cs;
	stack s;
	token *t;
	int a, b, c, n , m, flag=0, result;
	char x;

	init(&s);	
	cinit(&cs)
	while(1) {
		t = getnext (str);
		if(t->type == OPERAND) {
			push(&s, t -> number);
			
			if (flag == 1) {
				n=pop(&s);
				m=pop(&s);
				x=cpop(&cs);
				push(&s, operation(m, n, x));
				flag=0;
			}		
		}
		else if (t->type == OPERATOR) {
			if(!cempty(&cs)) {
				x = ctop(&cs);	
				a = precedence(x);	
				b = precedence(t->op);	
				
				if(a >= b ) {
				
					x = cpop(&cs);
					cpush(&cs, t->op);
					n=pop(&s);
					m=pop(&s);
					
					push(&s, operation(m, n, x) );	
					
				}
				if (a < b) {
					cpush(&cs, t->op );			
					flag=1;
				}
			}
			else
				cpush(&cs, t->op);
			
		}
		else if (t->type == BRACKET) {
			c=infixeval(str);
			push(&s, c);
			if (flag == 1) {
				n=pop(&s);
				m=pop(&s);
				x=cpop(&cs);
				push(&s, operation(m, n, x));
				flag=0;
			}				

		}
		else if (t->type == END) {
			while(!cempty(&cs)) {
				x = cpop(&cs);
				n=pop(&s);
				m=pop(&s);
				push(&s, operation(m, n, x) );	
				
			}
			result=pop(&s);
			return result;
		}
			
	}
			
}
int main( {
	char str[128];
	int x, ans;
	while((x = readline(str, 128))) {
		reset=1;
		ans = infixeval(str);
		if(ans == INT_MIN) {
			fprintf(stderr, "Error in expression\n");
		}  
		else
			fprintf(stdout, "%d\n", ans);
	return 0;
	}
}
