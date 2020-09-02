#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    ifstream input("input.txt");
    //считываем значение N (строки), значение M (столбцы)
    int n, m;
    if(input) {
        input >> n;
        input.ignore(1);
        input >> m;
    }
    int num;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            input >> num;
            input.ignore(1);
            cout <<setw(10) << num;
            if(j != m-1) {
                cout << " "; //Если не дошли до конца строки
            }
        }
        if(i != n-1) { //Если дошли до конца строки
            cout << endl;
        }
    }
    return 0;
}
