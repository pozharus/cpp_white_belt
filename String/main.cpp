#include <iostream>
#include <algorithm>
#include <iostream>
class ReversibleString {
public:
    ReversibleString() {
        //Конструктор по умолчанию
    }
    ReversibleString(const std::string& s) { //Конструктор с параметром
        saved_s = s;
    }
    void Reverse() {
        std::reverse(std::begin(saved_s), std::end(saved_s));
    }
    std::string ToString() const{
        return saved_s;
    }

    std::string saved_s;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    std::cout << s.ToString() << std::endl;
    s.Reverse();
    const ReversibleString& s_ref = s;
    std::string tmp = s_ref.ToString();
    std::cout << tmp << std::endl;
    ReversibleString empty;
    std::cout << '"' << empty.ToString() << '"' << std::endl;
    return 0;
}
