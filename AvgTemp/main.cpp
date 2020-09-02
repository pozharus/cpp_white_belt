#include <iostream>
#include <vector>
using namespace std;

void GetNumAvgTemp(vector<int> temp) {
    int sum_temp = 0;
    for(auto i : temp) {
         sum_temp += i;
    }
    int avg_temp = sum_temp / temp.size();

    int avg_temp_days_cnt = 0;
    vector<int> avg_temp_days = {};
    for(int j = 0; j < temp.size(); ++j) {
        if(temp[j] > avg_temp) {
            avg_temp_days.push_back(j);
            avg_temp_days_cnt++;
        }
    }

    cout << avg_temp_days_cnt << endl;
    for(auto k : avg_temp_days) {
        cout << k << " ";
    }
}
int main() {
    vector<int> temp = {};
    int n;
    cin >> n;

    int n_i;

    for(int i = 0; i < n; ++i) {
        cin >> n_i;
        temp.push_back(n_i);
    }

    GetNumAvgTemp(temp);


    return 0;
}
