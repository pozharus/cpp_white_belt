#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, set<string>> syn;

    while(q > 0) {
        string code;
        cin >> code;

        if(code == "ADD") {
        string w1;
        string w2;
        cin >> w1 >> w2;

        syn[w1].insert(w2); //В словарь с ключом w1 добавляем синоним w2
        syn[w2].insert(w1); //Добавляем наоборот, что бы можно было искать по индексам
        /*
        for(auto& index : syn) {
            cout << index.first << ": ";
            for(auto& item : index.second) {
                cout << item << " ";
            }
        }
         */
        }
        if(code == "COUNT") {
            string w;
            cin >> w;

            cout << syn[w].size() << endl;

        }
        if(code == "CHECK") {
            //сделать проверку "крест на крест"
            string check1, check2;
            cin >> check1 >> check2;
            if(syn[check1].count(check2) || syn[check2].count(check1)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

        --q;
    }
    return 0;
}
