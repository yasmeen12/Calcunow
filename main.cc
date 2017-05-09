#include <iostream>
#include <sstream>
#include "calc.h"
using namespace std;

int main() {
	//Sample input: 
	//x = 10 
	//x + 43
	string input = "";
	vector<string> calcInputs;
	while (cin) {
		getline(cin, input);

		istringstream iss(input);

		string word;

		while(iss >> word) {
			calcInputs.push_back(word);
		}

		if( calcInputs.at(1) == "=") set_value(calcInputs.at(0)[0], stoi(calcInputs.at(2)));

		cout << math(calcInputs);

	}
}
