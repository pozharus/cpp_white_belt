#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
 * Для каждого слова с помощью словаря подсчитаем, сколько раз в нём встречается каждая буква.
 * Если для обоих слов эти словари равны (а это проверяется с помощью обычного оператора ==),
 * то слова являются анаграммами друг друга, в противном случае не являются. При этом построение
 * такого словаря по слову удобно вынести в отдельную функцию BuildCharCounters.
 */

/*
 * Возвращает словарь с подсчитанными символами разбитого входного слова
 */
map<char, int> BuildCharCounters(const string& word) {
    map<char, int> result;
    for(auto& index : word) {
        result[index] += 1; // если символ [index] совпадает, делаем инкремент
    }
    return result;
}

int main() {
    int i;
    cin >> i;
    while (i > 0) {
        string word1;
        string word2;
        cin >> word1 >> word2; //Получаем входную пару

        map<char, int> word1_sort = BuildCharCounters(word1);
        map<char, int> word2_sort = BuildCharCounters(word2);

        if (word1_sort == word2_sort) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;

        --i;
    }
    return 0;
}
