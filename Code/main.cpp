#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "./string_calculator.h"

using std::cout; 
using std::endl;
using std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    string u, T;
    getline(cin,u);
    string out;

    while (u != "quit" && u != "q"){
        cout << ">> " << endl;
        std::stringstream x(u);
        string ls[3] = {" "," "," "};
        int i = 0;
        while (getline(x, T, ' ')) {
            ls[i] = T;
            i++;
        }

        if (ls[1] == "+"){
            out = add(ls[0], ls[2]);
        }
        else if (ls[1] == "*"){
            out = multiply(ls[0], ls[2]);
        }
        
        cout << "ans =" << endl;
        cout << endl;
        cout << "    " << out << endl;
        cout << endl;
        getline(cin,u);
    }

    cout << ">> " << endl;
    cout << "farvel!" << endl;
    cout << endl;
    
    // TODO(student): implement the UI
}

