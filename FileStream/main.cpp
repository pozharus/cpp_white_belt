#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    ifstream input("input.txt");
    ofstream output("output.txt");
    string str;
    while(getline(input,str)) {
        output << str << endl;
    }


    return 0;

}
