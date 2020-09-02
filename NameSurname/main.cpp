#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto& item : names) {
        // если очередной год не больше данного, обновляем имя
        if (item.first <= year) {
            name = item.second;
        } else {
            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
            break;
        }
    }

    return name;
}

vector<string> FindNameByYearWithHistory(const map<int, string>& names, int year) {
    vector<string> names_history;

    int limit = names.begin()->first; //int итератор (год) на конец словаря (первая дата)

    for(int i = year; i >= limit; --i) { //движемся year -> limit [левая граница]
        if(names.count(i)) { //Если такой год содержится в словаре
            names_history.push_back(names.at(i));
        }
    }
    return names_history;
}

string GetParsedStringFromVec(const vector<string>&vs) {
    string result; // = " (";

    string check = vs[0];

    unsigned int limit = vs.size()-1;

    for(unsigned int i = 1; i < limit; ++i) { //проходим по всему вектору
        if(check != vs[i]) { //если текущий элемент вектора не первый
            result += vs[i] + ", "; //ставим после него запятую и записываем результат
            check = vs[i];
        }
    }

    if(vs[limit] != check) //если не достигли конца
        result += vs[limit]; //записываем
    if(!result.empty())
    {
        return " (" + result + ")";
    }
    //result += ")";
    return result;
}

class Person {
public:
    Person(const string& first_name, const string& last_name, int year) {
        p_name = first_name;
        p_surname = last_name;
        p_year = year;
        first_names[p_year] = p_name;
        last_names[p_year] = p_surname;
    }
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) const {
        // получаем имя и фамилию по состоянию на год year
        const string first_name = FindNameByYear(first_names, year);
        const string last_name = FindNameByYear(last_names, year);

        if(year < p_year) {
            return "No person";
        }
        // если и имя, и фамилия неизвестны
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";

            // если неизвестно только имя
        } else if (first_name.empty()) {
            return last_name + " with unknown first name";

            // если неизвестна только фамилия
        } else if (last_name.empty()) {
            return first_name + " with unknown last name";

            // если известны и имя, и фамилия
        } else {
            return first_name + " " + last_name;
        }
    }

    string GetFullNameWithHistory(int year) const {
        vector<string> first_names_history = FindNameByYearWithHistory(first_names, year);
        vector<string> last_names_history = FindNameByYearWithHistory(last_names, year);

        if(year < p_year) {
            return "No person";
        }

        string result;
        if(!first_names_history.empty() && !last_names_history.empty()) {
            result = first_names_history[0];
            if(first_names_history.size() > 1) {
                result += GetParsedStringFromVec(first_names_history);
            }

            result += (" " + last_names_history[0]);
            if(last_names_history.size() > 1)
            {
                result += GetParsedStringFromVec(last_names_history);
            }
            return result;
        }
        else if(!first_names_history.empty()) {
            result = first_names_history[0];
            if(first_names_history.size() > 1)
            {
                result += GetParsedStringFromVec(first_names_history);
            }
            result += " with unknown last name";
        }
        else if(!last_names_history.empty())
        {
            result = last_names_history[0];
            if(last_names_history.size() > 1)
            {
                result += GetParsedStringFromVec(last_names_history);
            }
            result += " with unknown first name";
        } else result = "Incognito";

        return result;
    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
    string p_name;
    string p_surname;
    int p_year;
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    return 0;
};