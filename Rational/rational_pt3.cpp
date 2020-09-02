#include <iostream>
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
    return lhs.Numerator() == rhs.Numerator() and lhs.Denominator() == rhs.Denominator();
}
// Реализуйте для класса Rational операторы * и /
Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator()*rhs.Numerator(),lhs.Denominator()*rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator()*rhs.Denominator(),lhs.Denominator()*rhs.Numerator());
}
int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
