#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<string> stops;
    map<vector<string>,int> stops_to_bus_num;

    int counter = 1;
    while( q > 0) {
        int stop_count;
        cin >> stop_count;

        string stop_name;

        while(stop_count > 0) {
            cin >> stop_name;
            stops.push_back(stop_name);
            --stop_count;
        }

        /*
        for(auto& indx : stops) {
            cout << indx << " ";
        }*/

            if(!stops_to_bus_num.count(stops)) { //сравниваем индекс-вектор словаря и текущий введенный вектор
                stops_to_bus_num[stops] = counter;
                ++counter;
                for(auto& i : stops_to_bus_num) {
                    if (i.first == stops) {
                        cout << "New bus " << i.second <<endl;
                        /*
                        for (auto &item : i.first) {
                            cout << item << " ";
                        }*/
                    }
                }
            } else {
                /*
                for(auto& index : stops_to_bus_num) {
                    if(index.first == stops) {
                        cout << "Already exists for " << index.second << endl;
                    }
                }
                 */
                cout << "Already exists for " << stops_to_bus_num[stops] << endl;
            }

        stops.clear();
        --q;
    }
    return 0;
}
