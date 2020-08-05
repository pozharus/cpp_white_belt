#include <iostream>
#include <set>
#include <map>
#include <sstream>

using namespace std;

//TODO::Иметь ввиду на случай багов:
// 1.Преобразование к string выводов сообщений об ошибках
// 2.Первая строка при вводе комманд не считывается
// 3. Парсинг даты вида %3423$-12-12, не создается объект и не добавляется словарь,
// но не выводит error
// 4. Парсинг даты из примеров
// 5. Год может быть "0"

string SetPrintDateFormat(const int date, char key) {
    string str_date = to_string(date);
    int date_length = 0;
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
            date_length = str_date.size();
    }
    if(str_date.size() < date_length) {
        string new_str_date;
        while(new_str_date.size() != date_length-str_date.size()) {
            new_str_date += "0";
        }
        new_str_date += str_date; //[00str_date]
        return new_str_date;
    } else {
        return str_date;
    }
}

void CheckDateFormat(const char& delim) {
    if(delim != '-') {
        string msg("Wrong date format: ");
        throw runtime_error(msg);
    } //else: do nothing
}
void CheckMonth(const int& month) {
    if(month < 1 or month > 12) {
        stringstream ss;
        ss << "Month value is invalid: " << month;
        throw invalid_argument(ss.str());
    }   //else: do nothing
}
void CheckDay(const int& day) {
    if(day < 1 or day > 31) {
        stringstream ss;
        ss << "Day value is invalid: " << day;
        throw invalid_argument(ss.str());
    }   //else: do nothing
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

    bool DeleteEvent(const Date& date, const string& event) {
        int i = 0;
        i = db_struct.at(date).erase(event); //Удаляет отдельное событие по дате
        return i != 0;

    }
    void  DeleteDate(const Date& date) {
        db_struct.erase(date); //Удаляет всю дату
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
                cout << SetPrintDateFormat(index.first.GetYear(), 'y') << "-";
                cout << SetPrintDateFormat(index.first.GetMonth(), 'm') << "-";
                cout << SetPrintDateFormat(index.first.GetMonth(), 'd');
                for (auto &item : index.second) {
                    cout << " " << item; //item as set<events>
                }
                cout << endl;
            }
        }
    }

    int GetCountEventForDate(const Date& date) {
        return db_struct[date].size();
    }



private:
    map<Date, set<string>> db_struct;
};

Date CheckAndReturnDate(istream& stream_date) {
    //1970-04-23
    int year = 0;
    int month = 0;
    int day = 0;

    stream_date >> year;
    CheckDateFormat(stream_date.peek());
    stream_date.ignore(1);
    stream_date >> month;
    CheckMonth(month);
    CheckDateFormat(stream_date.peek());
    stream_date.ignore(1);
    stream_date >> day;
    CheckDay(day);
    //В итоге дата будет либо: целые положительные числа, либо отрицательные
    //или 0 - по умолчанию. Но не будут пустыми, т.к. изначально определены как 0.
    //Логически: ' ' => 0

    Date date{year,month,day};
    return date;
}

int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        // Считайте команды с потока ввода и обработайте каждую
        cin >> command;
        if (command == "Add") {
            string event;
            string str_date; //Строка для ввода даты
            cin >> str_date >> event; //Вводим дату в строку [Y-M-D]
            istringstream stream_date(str_date); //Создаем поток для посимвольного парсинга даты

            try {
                Date new_date;
                new_date = CheckAndReturnDate(stream_date);
                db.AddEvent(new_date, event);
            } catch (runtime_error &ex) {
                cout << ex.what() << str_date;
                return 0;
            } catch (invalid_argument &ex) {
                cout << ex.what();
                return 0;
            }

        } else if (command == "Print") {
            db.Print();

        } else if (command == "Del") {
            string data_str;
            getline(cin,data_str); //Читаем всю строку до enter
            istringstream in(data_str);
            string date, event;
            in >> date;
            in >> event;
            istringstream stream_date(date); //Создаем поток для посимвольного парсинга даты
            Date new_date = CheckAndReturnDate(stream_date);
            if(event.empty()) {
                int n_events = db.GetCountEventForDate(new_date);
                db.DeleteDate(new_date);
                cout << "Deleted " << n_events << " events";
            } else {
                if (db.DeleteEvent(new_date, event)) {
                    cout << "Deleted successfully";
                } else {
                    cout << "Event not found";
                }
            }
        } else if(command == "Find") {
            string date;
            cin >> date;
            istringstream stream_date(date);
            Date date_obj = CheckAndReturnDate(stream_date);
            set<string> events = db.Find(date_obj);
            for(auto& item : events) {
                cout << item << endl;
            }
        } else {
                cout << "Unknown command: " << command << endl;
                return 0;
            }
        }
    return 0;
}