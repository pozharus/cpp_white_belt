#include <iostream>
class Incognizable {
public:
    Incognizable() {}
    Incognizable(int num) {};
    Incognizable(int num1, int num2) {};
};
int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
    return 0;
}
