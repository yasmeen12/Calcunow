#include <iostream>
using namespace std;

//string either number or single letter
//if single_letter -> refer to class, get value for letter
//convert char into an integer

unsigned char get_val(string value) {
    if(isdigit(value[0])) {
        return stoi(value);
    } else {
        unsigned char placeHolder = value[0];
        return table.at(placeHolder)->get_val();
    }
};

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
