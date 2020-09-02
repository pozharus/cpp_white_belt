#include <iostream>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for(auto str : source) {
        destination.push_back(str);
    }
    source.clear();
}
int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};

    MoveStrings(source, destination);

    return 0;
}
