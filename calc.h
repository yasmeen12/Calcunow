#include <iostream>
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
        int get_val () {
            unsigned char temp = val;
            val++;
            if (val == 0){
                cout << "bad input from class" << endl;
            }
            return temp;

    }
};
