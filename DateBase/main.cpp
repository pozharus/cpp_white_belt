#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
using namespace std;

string global_date;

void PrintDateFormat(const int date, char key) {
    int date_length;
    switch(key) {
        case 'y':
            date_length = 4;
            break;
        case 'm':
            date_length = 2;
            break;
        case 'd':
            date_length = 2;
            break;
        default:
            date_length = 0;
    }

    cout << setw(date_length) << setfill('0') << date;
}

void CheckDateFormat(const char& delim) {
    if(delim != '-') {
        string msg("Wrong date format: ");
        msg += global_date;
        throw runtime_error(msg);
    }
}
void CheckMonth(const int& month) {
    if(month < 1 or month > 12) {
        stringstream ss;
        ss << "Month value is invalid: " << month;
        throw runtime_error(ss.str());
    }
}
void CheckDay(const int& day) {
    if(day < 1 or day > 31) {
        stringstream ss;
        ss << "Day value is invalid: " << day;
        throw runtime_error(ss.str());
    }
}

// Реализуйте функции и методы классов и при необходимости добавьте свои
class Date {
public:
    Date() {
        new_year = 0;
        new_month = 0;
        new_day = 0;
    }
    Date(const int& year, const int& month, const int& day) {
        new_year = year;
        new_month = month;
        new_day = day;
    }
    int GetYear() const {
        return new_year;
    }
    int GetMonth() const {
        return new_month;
    }
    int GetDay() const {
        return new_day;
    }
private:
    int new_year;
    int new_month;
    int new_day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if(lhs.GetYear() == rhs.GetYear()) {
        if(lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        } else {
            return lhs.GetMonth() < rhs.GetMonth();
        }
    } else {
        return lhs.GetYear() < rhs.GetYear();
    }
}

class Database {
public:

    void AddEvent(const Date& date, const string& event) {
         db_struct[date].insert(event);
    }

    int DeleteEvent(const Date& date, const string& event) {
        int flag;
        flag = db_struct.at(date).erase(event); //Удаляет отдельное событие по дате
            if(db_struct.at(date).empty() and flag == 1) {
                db_struct.erase(date);
            }
        return flag;
    }

    int  DeleteDate(const Date& date) {
        int count = db_struct.at(date).size();
        db_struct.erase(date); //Удаляет всю дату
        return count;
    }

    set<string> Find(const Date& date) const {
        set<string> events_for_date;
        auto events_for_date_obj = db_struct.find(date);
        if(events_for_date_obj != db_struct.end()) {
            for (auto &index : events_for_date_obj->second) {
                events_for_date.insert(index);
            }
        }
        return events_for_date;
    }

    void Print() const {
        if(!db_struct.empty()) {
            for (auto &index : db_struct) {
                for (auto &item : index.second) {
                    PrintDateFormat(index.first.GetYear(), 'y'); cout << "-";
                    PrintDateFormat(index.first.GetMonth(), 'm'); cout << "-";
                    PrintDateFormat(index.first.GetDay(), 'd'); cout << " ";
                    cout << item; //item as set<events>
                    cout << endl;
                }
            }
        }
    }

private:
    map<Date, set<string>> db_struct;
};

Date CheckAndReturnDate(istream& stream_date) {
    int year = 0;
    int month = 0;
    int day = 0;

    string msg("Wrong date format: ");
    msg += global_date;

    stream_date >> year;
    CheckDateFormat(stream_date.peek());
    stream_date.ignore(1);
    month = stream_date.peek();
    if (month==EOF) {
        throw runtime_error(msg);
    }
    stream_date >> month;

    CheckDateFormat(stream_date.peek());
    stream_date.ignore(1);

    day = stream_date.peek();
    if (day==EOF) {
        string er = "Wrong date format: " + global_date;
        throw runtime_error(msg);
    }
    stream_date >> day;

    CheckMonth(month);
    CheckDay(day);

     string ending;
     stream_date >> ending;
     if(!ending.empty()) {
         throw runtime_error(msg);
     }

     Date date{year,month,day};
     return date;
}

int main() {
    Database db;
    string buffer;
    while (getline(cin, buffer)) { //Считали полную строку
        istringstream query(buffer);
        string command;
        query >> command;

        if (command == "Add") {
            string event;
            string str_date; //Строка для ввода даты
            query >> str_date; //Вводим дату в строку [Y-M-D]
            query >> event;
            global_date = str_date;
            istringstream stream_date_add(str_date); //Создаем поток для посимвольного парсинга даты

            try {
                Date new_date;
                new_date = CheckAndReturnDate(stream_date_add);
                db.AddEvent(new_date, event);
            } catch (runtime_error &ex) {
                cout << ex.what() << endl;
                return 0;
            }

        } else if (command == "Print") {
            db.Print();

        } else if (command == "Del") {
            string date, event;
            query >> date;
            query >> event;
            istringstream stream_date_del(date); //Создаем поток для посимвольного парсинга даты
            global_date = date;
            try { //Пробуем создавать объект с датой
                Date new_date = CheckAndReturnDate(stream_date_del);
                if (event.empty()) {
                    try {
                        int n_events = db.DeleteDate(new_date);
                        cout << "Deleted " << n_events << " events" << endl;
                    } catch (out_of_range &ex) { //Ловим исключение out of range, если есть попытка удалить несуществующую дату
                        cout << "Deleted 0 events" << endl;
                    }
                } else {
                    try {
                        int count_of_del_ev;
                        count_of_del_ev = db.DeleteEvent(new_date, event);
                        if (count_of_del_ev == 1) {
                            cout << "Deleted successfully" << endl; //Для существующей даты, если есть заданное событие
                        } else {
                            cout << "Event not found" << endl; //Если для существующей даты не задано событие
                        }
                    } catch (out_of_range &ex) {
                        cout << "Event not found" << endl;
                        }
                    }
                } catch (runtime_error &ex) { //Если дата неккоректна по формату бросаем ошибку
                    cout << ex.what() << endl;
                    return 0;
            }
        } else if(command == "Find") {
            string date;
            query >> date;
            istringstream stream_date_find(date);
            global_date = date;
            try {
                Date date_obj = CheckAndReturnDate(stream_date_find);
                set<string> events = db.Find(date_obj);
                for (auto &item : events) {
                    cout << item << endl;
                }
            } catch (runtime_error &ex) {
                cout << ex.what() << endl;
                return 0;
            }
        } else if(command.empty()) {
            continue;
        } else {
                cout << "Unknown command: " << command << endl;
                return 0;
        }
        buffer.clear();
        global_date.clear();
    }
    return 0;
}