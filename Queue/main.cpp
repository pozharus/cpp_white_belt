#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Можно использовать как вектор строк ("true" / "false")
 * Так и вектор bool (1/0)
 * Исправить строку на булевое значение (или наоборот)
 */
int main() {

    vector<bool> queue = {}; //пустой вектор очереди

    int q;
    cin >> q;
    int flag_num;
    int index;
    string flag;

    while(q > 0) {
        cin >> flag;

        if(flag == "WORRY") {
            flag_num = 0;
        } else if(flag == "QUIET") {
            flag_num = 1;
        } else if(flag == "COME") {
            flag_num = 2;
        } else if(flag == "WORRY_COUNT") {
            flag_num = 3;
        }

        switch (flag_num) {
            case 0:
                cin >> index;

                queue[index] = false;
                /*
                for(auto item : queue) {
                    cout << item << endl;
                }*/
                break;
            case 1:
                cin >> index;

                queue[index] = true;


                /*
                for(auto item : queue) {
                    cout << item << endl;
                }
                 */
                break;
            case 2:
                cin >> index;
                if(index > 0) {
                    for(int i = 0; i<index; i++) {
                        queue.emplace_back(true);
                    }
                    //cout << "Hint: now queue size is: " << queue.size() << endl;
                } else if (index < 0){
                    int new_size = index + queue.size();
                    queue.resize(new_size);

                    //cout << "Hint: now queue size is: " << queue.size() << endl;
                    /*
                    for(auto item : queue) {
                        cout << item << endl;
                    }*/
                }
                break;
            case 3:
                int worry_count = 0;
                for(int i = 0; i < queue.size(); ++i) {
                    if(queue[i] == false) {
                        worry_count++;
                    }
                }
                cout << worry_count <<endl;
                break;
        }
     q--;
    }
    return 0;
}