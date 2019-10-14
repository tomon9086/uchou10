#include <variant>

using namespace std;

namespace ast {
	typedef enum {
		TOKEN_ROOT,
		TOKEN_NUMBER,
		TOKEN_OPERATOR
	} TokenType;

	typedef enum {
		OPERATOR_ADD,
		OPERATOR_SUBTRACT
	} OperatorType;

	typedef struct Token {
		TokenType type;
		Token *next;
	} Token;

	typedef struct Number: Token {
		double val;
	} Number;

	typedef struct Operator: Token {
		OperatorType op_type;
	} Operator;
}
