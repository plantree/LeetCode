#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    // solution 1
    /*
    while ((n % 2 != 1) && n != 1) {
        n /= 2;
    }
    if (n == 1) {
        return true;
    } else {
        return false;
    }*/

    // solution 2
    int count = 0;
    while (n > 0) {
        count += (n & 1);
        n = n >> 1;
    }
    return count == 1;
}

int main() {
    int n = 1;
    cout << isPowerOfTwo(n) << endl;
    n = 16;
    cout << isPowerOfTwo(n) << endl;
    n = 218;
    cout << isPowerOfTwo(n) << endl;
}