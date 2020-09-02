#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        strings.push_back(s);
    }

    vector<string> GetSortedStrings() {
        sort(begin(strings), end(strings));
        return strings;
    }

    void PrintSortedStrings(SortedStrings& strings) {
        for (const string& s : strings.GetSortedStrings()) {
            cout << s << " ";
        }
        cout << endl;
    }

    void PrintStrings() {
        for(const string& s : strings) {
            cout << s << " ";
        }
        cout << endl;
    }

private:
    vector<string> strings;
};

int main() {
    SortedStrings strings;
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    strings.PrintStrings();
    strings.PrintSortedStrings(strings);
    strings.AddString("second");
    strings.PrintStrings();
    strings.PrintSortedStrings(strings);



    return 0;
}
