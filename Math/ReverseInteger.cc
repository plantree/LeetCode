#include <iostream>

using namespace std;

int reverse(int x) {
    if (x == 0) {
        return x;
    }
    int res = 0;
    while (x) {
        if(res > 2147483647/10 || res < -2147483647/10) {
            return 0;
        } 
        res = 10 * res + (x % 10);
        x /= 10;
    }
    return res;
}

int main() {
    cout << reverse(123) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(120) << endl;
}