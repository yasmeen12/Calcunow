#include <iostream>
#include <sstream>
#include "calc.h"
using namespace std;

int main() {
    //Sample input:
    //x = 10
    //x + 43
    //Fill vector with calc objects - 26 for each letter of the alphabet
    for(int i = 0; i < 26; i++) table.push_back(new calc);
    
    string input = "";
    int looping = 0; 
    
    while (true) {
        vector <string> calcInputs;
        //Check for End of File
        auto c = cin.peek();
        if (c == EOF) break;
        getline(cin, input);

        istringstream iss(input);

        string word;

        //Break up input and push each word/variable/symbol/number into vector - Robert
        while(iss >> word) {
            calcInputs.push_back(word);
        }
        
        //Functions in calc.h can throw runtime errors, use try-catch block to handle errors - Robert
        try {
            //Extra Credit: Looping
            if(looping > 0) { 
                for (int i = 0; i < looping; i++) {
                    cout << math(calcInputs) << endl;   
                }
                looping = 0;
            }
            //Handle User inputs
            else if( calcInputs.at(0) == "LET") set_value(calcInputs.at(1)[0], stoi(calcInputs.at(3)));
            else if(calcInputs.at(0) == "QUIT" || calcInputs.at(0) == "quit") break;
            else if(calcInputs.at(0) == "LOOP") looping = stoi( calcInputs.at(1));
            else cout <<  math(calcInputs) << endl;
        } catch (exception &e) {
            //Handle thrown runtime errors - Robert   
            cout << "INVALID INPUT!\n";            
            exit(EXIT_FAILURE);   
        }     
    }    
}
