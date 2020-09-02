#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string str) {
    if(str.length() == 1) {
        return true;
    } else {
        for(int i = 0; i < str.length()/2; ++i) {
            if(str[i] != str[str.length() - i - 1]) {
                return false;
            }
        }
    }

    return true;
}
int main() {
    string str;
    cin >> str;
    cout << IsPalindrom(str);
    return 0;
}