#include <iostream>
#include <sstream>
#include "calc.h"
using namespace std;

int main() {
    //Sample input:
    //x = 10
    //x + 43
    for(int i = 0; i < 26; i++) table.push_back(new calc);
    string input = "";
   int looping = 0; 
    while (true) {
        vector <string> calcInputs;
        auto c = cin.peek();
        if (c == EOF) break;
        getline(cin, input);

        istringstream iss(input);

        string word;

        while(iss >> word) {
            calcInputs.push_back(word);
        }
        try{
           if( looping > 0) {
                  for (int i = 0; i < looping; i++) {
                      cout << math(calcInputs) << endl;
                  }
              looping = 0;
              }
              else if( calcInputs.at(0) == "LET") set_value(calcInputs.at(1)[0], stoi(calcInputs.at(3)));
              else if(calcInputs.at(0) == "QUIT" || calcInputs.at(0) == "quit") break;
              else if(calcInputs.at(0) == "LOOP") looping = stoi( calcInputs.at(1));
            else cout <<  math(calcInputs) << endl;
        } catch (exception &e) {
                cout << "INVALID INPUT!\n";
                exit(EXIT_FAILURE);
            }
        }
    }
