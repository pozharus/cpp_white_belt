#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

class Rational {
    // Вставьте сюда реализацию класса Rational из первой части
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        new_numerator = 0;
        new_denominator = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        new_numerator = numerator;
        new_denominator = denominator;

        int gcd = std::gcd(new_numerator, new_denominator);

        new_numerator = new_numerator / gcd;
        new_denominator = new_denominator / gcd;

        if(new_denominator < 0) {
            new_denominator = abs(new_denominator);
            new_numerator = -new_numerator;
        }
    }

    int Numerator() const {
        // Реализуйте этот метод
        return new_numerator;
    }

    int Denominator() const {
        // Реализуйте этот метод
        return new_denominator;
    }


private:
    // Добавьте поля
    int new_numerator;
    int new_denominator;
};

// Вставьте сюда реализацию operator == для класса Rational из второй части

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * lhs.Denominator() == rhs.Numerator() * rhs.Denominator();
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

bool operator<(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
