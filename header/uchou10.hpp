#include <iostream>
#include <string>

#include "./ast.hpp"

using namespace std;
using namespace ast;

namespace uchou10 {
	Token *tokenize(string line) {
		Token *root = (Token*)malloc(sizeof(Token));
		root->type = TOKEN_ROOT;
		root->next = NULL;

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
					Number *num;
					if(curr->type == TOKEN_NUMBER) {
						num = (Number*)curr;
					} else {
						num = (Number*)malloc(sizeof(Number));
						num->val = 0;
						curr->next = num;
						curr = num;
					}
					num->type = TOKEN_NUMBER;
					num->val = stoi(to_string((int)num->val) + &c);
					num->next = NULL;
					break;
				}
				default:
				{
					cerr << "unexpected token: \"" << c << "\"" << endl;
					root->next = NULL;
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
