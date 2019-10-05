#include <iostream>
#include <string>

#include "./ast.hpp"

using namespace std;

namespace uchou10 {
	void interpret(string source, bool quiet = false) {
		Number *num = (Number*)malloc(sizeof(Number));
		num->type = TOKEN_NUMBER;
		num->val = stod(source);
		cout << num->val << endl;
	}
}
