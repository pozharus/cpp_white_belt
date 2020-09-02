#include <iostream>
#include <exception>

using namespace std;

int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GreatestCommonDivisor(b, a % b);
    }
}

class Rational {
    // Вставьте сюда реализацию класса Rational
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

        if(new_denominator == 0) {
            throw invalid_argument("Invalid denominator: 0");
        }

        int gcd = GreatestCommonDivisor(new_numerator, new_denominator);

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

// Вставьте сюда реализацию operator / для класса Rational
Rational operator/(const Rational& lhs, const Rational& rhs) {
    if(rhs.Numerator() == 0) {
        throw domain_error("Error: Try to div on zero");
    }
    return Rational(lhs.Numerator()*rhs.Denominator(),lhs.Denominator()*rhs.Numerator());
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
