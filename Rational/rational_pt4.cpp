#include <iostream>
#include <sstream>
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
// Реализуйте для класса Rational операторы << и >>
istream& operator >> (istream& is, Rational& r) {
  int n, d;
  char c;
  
  if (is) {
      is >> n >> c >> d;
      if (is && c == '/') {
          r = Rational(n, d);
      }
  }
  
  return is;
}

ostream& operator << (ostream& os, const Rational& r) {
  return os << r.Numerator() << '/' << r.Denominator();
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
