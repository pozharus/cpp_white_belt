#include <iostream>
#include <vector>
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

vector<string> PalindromFilter(vector<string>words, int minLength) {

    vector<string> palindromsByLen;

    for (auto wrd : words) {
        if(IsPalindrom(wrd) == true) {
            if(wrd.length() >= minLength) {
                palindromsByLen.push_back(wrd);
            }
        }
    }

    return palindromsByLen;
}



int main() {
    vector<string> words = {"abacaba","aba"};
    vector<string> filterWords;

    filterWords = PalindromFilter(words,2);

    for(auto wrd : filterWords) {
        cout << wrd << endl;
    }

    return 0;
}
