#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    vector<int> buff;
    buff.clear();

    for(int i = v.size()-1; i >= 0; --i) {
        buff.push_back(v[i]);
    }

    v = buff;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);

    for(auto num : numbers) {
        cout << num << endl;
    }

    return 0;
}
