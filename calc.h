#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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
            if (val == 0) throw runtime_error("Bad!");
            return temp;
        }
};

vector<calc*> table;

void set_value(char var, int val) {
    int temp = var - 'a';
    //Check if value already set
    if(table.at(temp)->get_used() || val < 0 || val > 255) throw runtime_error("Bad!");
    table.at(temp)->set_val(val);
};

unsigned char get_val(string value) {
    if(isdigit(value[0])) {
        return stoi(value);
    } else {
        unsigned char placeHolder = value[0]- 'a';
        //check if value has not been set
        if(!table.at(placeHolder)->get_used()) throw runtime_error("Bad!");
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
            if(second_var == 0) throw runtime_error("Bad!");
            value = value / second_var;
        }
        if (operand == '%') {
            value = value % second_var;
        }
        if (operand == '^') {
            if(value == 0 || second_var == 0)
                throw runtime_error("Invalid Input!");
            else value = pow(value,second_var);
        }
    }
    return value;
}
