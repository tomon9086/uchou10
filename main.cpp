#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

void interpret(string source, bool quiet = false) {
	Number *num = (Number*)malloc(sizeof(Number));
	num->type = TOKEN_NUMBER;
	num->val = stod(source);
	cout << num->val << endl;
}

int main(int argc, char *argv[]) {
	string line;
	if(argc < 2) {
		while(1) {
			getline(cin, line);
			interpret(line);
			if(cin.eof()) {
				cout << "abort." << endl;
				return 0;
			}
		}
	}

	string filename = argv[1];
	ifstream file;

	file.open(filename);
	if(file.fail()) {
		cerr << filename << ": not such file or directory." << endl;
		return 1;
	}

	if(file.is_open()) {
		while(getline(file, line)) {
			interpret(line, true);
		}
		file.close();
	}

	return 0;
}
