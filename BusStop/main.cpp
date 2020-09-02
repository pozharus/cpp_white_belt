#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, vector<string>> bus_stops; //маршрут->остановки
    map<string, vector<string>> stop_buses; //остановка->маршрут
    vector<string> buses;


    while(q > 0) {
        string bus;
        string stop_name;
        string command_code;
        cin >> command_code;

        if (command_code == "NEW_BUS") {
            cin >> bus; //вводим название маршрута
            buses.push_back(bus);

            int stop_count;
            cin >> stop_count;
            while (stop_count > 0) {
                cin >> stop_name;

                bus_stops[bus].push_back(stop_name);
                stop_buses[stop_name].push_back(bus);

                --stop_count;
            }
        }

        if (command_code == "ALL_BUSES") {
            if (!bus_stops.empty()) { //Если вектор маршрутов не пустой
                for (auto &index : bus_stops) {
                    cout << "Bus " << index.first << ": "; //Список автобусов в алфавитном порядке

                    for (auto &item : index.second) {
                        cout << item << " ";
                    }
                    cout << endl;
                }

            } else {
                cout << "No buses" << endl;
            }
        }

        if (command_code == "BUSES_FOR_STOP") {
            cin >> stop_name;
            if (stop_buses.count(stop_name)) { //если stop_name содержится в buses
                for (auto &index : stop_buses) {
                    for (auto &item : index.second) {
                        if(index.first == stop_name) {
                            cout << item << " ";
                        }
                    }
                }
                cout << endl;
            } else {
                cout << "No stop" << endl;
            }

        }

        if(command_code == "STOPS_FOR_BUS") {
            cin >> bus;

            if (bus_stops.count(bus)) { //если такой автобус есть в списке
                for(auto& index : bus_stops) {
                    if(index.first == bus) {
                        for(auto& item : index.second) {
                            cout << "Stop " << item << ": "; //Перебираем список остановок для заданного маршрута
                            //по заданной остановке вывести список автобусов для данной остановки, исключая указанную
                            for(auto& i : stop_buses) {
                                for(auto& j : i.second) {
                                    if(i.first == item) {
                                        if(j != bus) {
                                            cout << j << " ";
                                        } else if(i.second.size() < 2) {
                                            cout << "no interchange";

                                        }

                                    }
                                }
                            } cout  << endl;

                        }
                    }
                }

            } else {
                cout << "No bus" << endl;
            }
        }

        --q;
    }

    return 0;
}
