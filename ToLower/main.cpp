#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N;
    vector<string> S;
    string s;
    cin >> N;
        if(N >= 0 && N <= 1000) {
            while(N > 0) {
                cin >> s;
                if(s.length() >= 1 && s.length() <= 15) {
                    S.push_back(s);
                }
                --N;
            }
        }
        sort(S.begin(), S.end(), [](string a, string b) {
            for(char& i : a) {
                i = tolower(i, locale()); //записываем обратно результат выполнения функции
            }
            for(char& i_1 : b) {
                i_1 = tolower(i_1, locale());
            }
            return a < b;
        });

        for(const auto& item : S) {
            cout << item << " ";
        }

    return 0;
}
