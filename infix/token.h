#define OPERAND 10 
#define OPERATOR 20
#define	END	30
#define ERROR	40
#define BRACKET 50
typedef struct token {
	int type; // type takes values OPERAND/OPERATOR/END/BRACKET
	int number;
	char op;
}token;
token *getnext(char *);
