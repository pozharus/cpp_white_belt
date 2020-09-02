#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    map<set<string>, int> stops_to_bus_num;
    set<string> stops;
    int q;
    cin >> q;
    while (q > 0) {
        int stop_count;
        cin >> stop_count;
        string stop_name;

        while (stop_count > 0) {
            cin >> stop_name;
            stops.insert(stop_name);
            --stop_count;
        }

            if(!stops_to_bus_num.count(stops)) {
                stops_to_bus_num[stops];
                int bus_num = stops_to_bus_num.size();
                stops_to_bus_num[stops] = bus_num;
                cout << "New bus " << stops_to_bus_num[stops] << endl;
            }  else {
                cout << "Already exists for " << stops_to_bus_num[stops] << endl;
            }

            stops.clear();
            --q;
        }
        return 0;
    }