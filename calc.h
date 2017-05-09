#include <iostream>
#include <string>
#include <vector>
using namespace std;

class calc{
    protected:
        unsigned char val;
        bool used;

    public:
        calc() {
            val = 0;
            used = false;
        }

        bool get_used () {return used;}
        void set_val (int a) {
            val = a;
            used = true;
        }
        unsigned char get_val () {
            unsigned char temp = val;
            val++;
            if (val == 0){
                cout << "bad input from class" << endl;
            }
            return temp;
        }
};

vector<calc*> table(26,new calc);

void set_value(char var, int val) {
    int temp = var - 'a';
    table.at(temp)->set_val(val);
};

unsigned char get_val(string value) {
    if(isdigit(value[0])) {
        return stoi(value);
    } else {
        unsigned char placeHolder = value[0];
        return table.at(placeHolder)->get_val();
    }
};

int math(vector<string> input) {
    int counter = 1;
    int value= get_val(input.at(0));

    while(counter < (int) input.size()) {
        char operand = input.at(counter).at(0);
        counter++;

        unsigned char second_var = get_val(input.at(counter));

        counter++;
        
        if (operand == '+') {
            value = value + second_var;
        }
        if (operand == '-') {
            value = value - second_var;
        }
        if (operand == '*') {
            value = value * second_var;
        }
        if (operand == '/') {
            value = value / second_var;
        }
        if (operand == '%') {
            value = value % second_var;
        }
        if (operand == '^') {
            value = value^second_var;
        }
    }
    return value;
}
