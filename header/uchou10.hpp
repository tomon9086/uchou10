#include <iostream>
#include <string>

#include "./ast.hpp"

using namespace std;
using namespace ast;

namespace uchou10 {
	Token *tokenize(string line) {
		Token *root = (Token*)malloc(sizeof(Token));
		root->type = TOKEN_ROOT;

		Token *curr = root;
		for(int i = 0; i < line.length(); i++) {
			char c = line[i];
			switch(c) {
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				{
					Number *num = (Number*)malloc(sizeof(Number));
					num->type = TOKEN_NUMBER;
					num->val = atoi(&c);
					num->next = NULL;
					curr->next = num;
					curr = num;
					break;
				}
				default:
				{
					cerr << "unexpected token: \"" << c << "\"" << endl;
				}
			}
		}
		return root;
	}

	void interpret(string source, bool quiet = false) {
		Token *t = tokenize(source);
		while(t->next) {
			Token *garbage = t;
			t = t->next;
			free(garbage);
			if(t->type == TOKEN_NUMBER) {
				cout << " val: " << ((Number*)t)->val << endl;
			} else {
				cout << "type: " << t->type << endl;
			}
		}
	}
}
