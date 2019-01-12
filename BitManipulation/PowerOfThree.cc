#include <iostream>
#include <cmath>

using namespace std;

bool isPowerOfThree(int n) {
    // solution 1
    /*
    if (n <= 0) {
        return false;
    }
    while ((n % 3) == 0 && n != 1) {
        n /= 3;
    }
    return n == 1;*/

    // solution 2
    auto temp = log10(n) / log10(3);
    return (n > 0 && (temp - int(temp) == 0));
}

int main() {
    int n = 27;
    cout << isPowerOfThree(n) << endl;
    n = 0;
    cout << isPowerOfThree(n) << endl;
    n = 9;
    cout << isPowerOfThree(n) << endl;
}