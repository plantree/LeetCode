#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    auto end = --digits.end();
    *end += 1;
    // 进1标志位
    int flag = 0;
    for (; end != digits.begin(); --end) {
        *end += flag;
        flag = 0;
        if (*end != 10) {
            break;
        } else {
            *end = 0;
            flag = 1;
        }
    }
    // 判断首位是否需要进1
    if (end == digits.begin()) {
       if ((*end + flag) == 10) {
            *end = 0;
            digits.insert(end, 1);
       } else {
           *end += flag;
       }
    }
    return digits;
}



int main() {
    vector<int> digits = {9, 9, 9};
    auto digitsPlus = plusOne(digits);
    for (auto digit : digitsPlus) {
        cout << digit << " ";
    }
}