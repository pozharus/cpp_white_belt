#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<int> A;
    int num;

    cin >> N;
        if(N >= 0 && N <= 1000) {
            while(N > 0) {
                cin >> num;
                if(num >= -1000000 && num <= 1000000) {
                    A.push_back(num);
                }
                --N;
            }
        }

        sort(begin(A), end(A), [](int a, int b) { //а - текущей элемент в сортировке
            return abs(a) < abs(b);
        });

        for(auto& item : A) {
            cout << item << " ";
        }

    return 0;
}
