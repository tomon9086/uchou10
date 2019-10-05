#include <iostream>
#include <fstream>
#include <string>

#include "./header/uchou10.hpp"

using namespace std;
using namespace uchou10;

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
