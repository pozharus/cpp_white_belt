#include <iostream>
#include <vector>
#include <string>
using  namespace std;
//TODO: учет месяцев в цикле с инкрементом при переходе на новый месяц
//31 х n, двумерний вектор состоит из 31-го вектора со списком дел (по дням)
//Одномерный вектор строк со списком задач, запихнут в двумерный вектор дней
//TODO сделать начало месяца с 1


int main() {
    int day_in_month = 31+1;
    int m = 1; //январь изначально

    vector<vector<string>> month(day_in_month); // Вектор -> 31-го векторов


    int q = 0;
    cin >> q;
    while(q > 0) {
        string action;
        cin >> action;

        if(action == "ADD") {
            string s;
            int i;
            cin >> i;
            cin >> s;
            month[i].push_back(s); //Добавляем задачи в вектор i-го дня
        }
        if(action == "DUMP") {
            int i;
            cin >> i;
            cout << month[i].size() << " ";
            for(auto x : month[i]) { //Выводим вектор і-го дня
                cout << x << " ";
            }
            cout << endl;
        }
        if(action == "NEXT") {
            m++;
            switch(m) {
                case 1:
                    day_in_month = 31+1;
                    break;
                case 2:
                    day_in_month = 28+1;
                    break;
                case 3:
                    day_in_month = 31+1;
                    break;
                case 4:
                    day_in_month = 30+1;
                    break;
                case 5:
                    day_in_month = 31+1;
                    break;
                case 6:
                    day_in_month = 30+1;
                    break;
                case 7:
                    day_in_month = 31+1;
                    break;
                case 8:
                    day_in_month = 31+1;
                    break;
                case 9:
                    day_in_month = 30+1;
                    break;
                case 10:
                    day_in_month = 31+1;
                    break;
                case 11:
                    day_in_month = 30+1;
                    break;
                case 12:
                    day_in_month = 31+1;
                    break;
                default:
                    m = 1;
                    break;
            } //Цикл постоянно крутится и проверяет, не изменили ли мы месяц





            //TODO: перекинуть содержимое векторов для дней, которые влезли в новый месяц
            //Для январь - февраль: задачи с 31, 30, 29 индекса перекинуть в 28
            int days = month.size();
            /*
            cout << "Hint: old countity of days: " << month.size() << endl;
            cout << "Hint: new countity of days: " << day_in_month << endl;
            cout << "used range start: " << day_in_month << endl;
            cout << "used range end: " << days-1 << endl;
            */
            if(day_in_month < month.size()) { //Если в новом месяце дней меньше, чем в предыдущем
                for(int i = day_in_month; i <= days-1; ++i) {
                    month[day_in_month - 1].insert(end(month[day_in_month - 1]), begin(month[i]),
                                                   end(month[i]));
                }
            }

            month.resize(day_in_month); //перейти на новый месяц
            /*
            cout << "Hint: new countity of days: " << month.size() << endl;

                for(int i = 0; i<month.size(); ++i) {
                for(int j = 0; j<month[i].size(); ++j) {
                    cout << "Day: " << i  << month[i][j] << " " << endl;
                }
            }
             */

        }
        --q;
    }



    return 0;
}
