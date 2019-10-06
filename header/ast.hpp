#include <variant>

using namespace std;

namespace ast {
	typedef enum {
		TOKEN_ROOT,
		TOKEN_NUMBER
	} TokenType;

	typedef struct Token {
		TokenType type;
		Token *next;
	} Token;

	typedef struct Number: Token {
		double val;
	} Number;
}
