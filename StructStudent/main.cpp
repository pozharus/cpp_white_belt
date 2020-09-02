#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student {
    string name;
    string surname;
    int day;
    int month;
    int year;
    int id;
};
int main() {
    vector<Student> students;
    int n;
    cin >> n; //Вводим число студентов
    int counter = n;
    int id = 0;
    if(n >= 0 and n <= 10000) {
        while (counter > 0) {
            string new_stud_name;
            string new_stud_surname;
            int new_stud_day;
            int new_stud_month;
            int new_stud_year;
            cin >> new_stud_name;
            cin >> new_stud_surname;
            cin >> new_stud_day;
            cin >> new_stud_month;
            cin >> new_stud_year;
            if(new_stud_name.size() >= 0 and new_stud_name.size() <= 15
                        and new_stud_surname.size() >= 0 and new_stud_surname.size() <= 15
                        and new_stud_day >= 0 and new_stud_day <= 1000000000
                        and new_stud_month >= 0 and new_stud_month <= 1000000000
                        and new_stud_year >= 0 and new_stud_year <= 1000000000) {
                //Если все условия по длинне символов выполняются, добавляем структуру
                id++;
                Student new_student;
                new_student.id = id;
                new_student.name = new_stud_name;
                new_student.surname = new_stud_surname;
                new_student.day = new_stud_day;
                new_student.month = new_stud_month;
                new_student.year = new_stud_year;

                students.push_back(new_student);
            }
            counter--;
        }
    }
    int m;
    cin >> m; //Вводим число запросов
    if(m >= 0 and m <= 10000) {
        //Запускаем м-число строк
        while(m > 0) {
            string query;
            cin >> query;
            int k;
            cin >> k;
            if(k > 0 and k <= n) { //query.size() > 0 and query.size() <= 15 and
                if(query == "name") {
                    for(const auto& student : students) {
                        //Перебираем структуру
                        if(student.id == k) {
                            //Если номер студента совпадает с искомым в запросе
                            cout << student.name << " " << student.surname << endl;
                            break;
                        }
                    }
                } else if (query == "date") {
                    for(const auto& student : students) {
                        //Перебираем структуру
                        if(student.id == k) {
                            //Если номер студента совпадает с искомым в запросе
                            cout << student.day << "." << student.month << "." << student.year << endl;
                            break;
                        }
                    }
                } else {
                    //Если несуществующая команда
                    cout << "bad request" << endl;

                }
            } else {
                //Если несуществующая команда
                cout << "bad request" << endl;

            }
            m--;
        }
    }
    return 0;
}
