typedef enum {
	TOKEN_NUMBER
} TokenType;

typedef struct Token Token;
struct Token {
	TokenType type;
};

typedef struct Number Number;
struct Number: Token {
	double val;
};


