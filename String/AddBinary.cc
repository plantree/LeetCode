#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
    string res = "";
    int m = a.size() - 1, 
        n = b.size() - 1,
        flag = 0;
    while (m >= 0 || n >= 0) {
        int p = m >= 0 ? a[m--] - '0' : 0;
        int q = n >= 0 ? b[n--] - '0' : 0;
        int sum = p + q + flag;
        res = to_string(sum % 2) + res;
        flag = sum / 2;
    }
    return flag == 1 ? "1" + res : res;
}

int main() {
    cout << addBinary("11", "1") << endl;
    cout << addBinary("1010", "1011") << endl;
}