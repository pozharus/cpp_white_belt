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

int lcd(const Rational& lhs, const Rational& rhs) {
    return gcd(lhs.Denominator(),rhs.Denominator())*lhs.Denominator()*rhs.Denominator();
}
// Реализуйте для класса Rational операторы ==, + и -
bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() and lhs.Denominator() == rhs.Denominator();
}
Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() + lhs.Denominator() *
                                                          rhs.Numerator(),rhs.Denominator() * lhs.Denominator());
}
Rational operator-(const Rational& lhs, const Rational& rhs) {
    if(lhs.Denominator() == rhs.Denominator()) {
        return Rational(lhs.Numerator()-rhs.Numerator(),lhs.Denominator());
    } else {
        return Rational((lhs.Numerator()*rhs.Denominator()-rhs.Numerator()*lhs.Denominator()),lhs.Denominator()*rhs.Denominator());
    }
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }


    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational (31, 63);;
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
