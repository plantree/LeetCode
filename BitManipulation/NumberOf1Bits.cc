#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    uint32_t n = 11;
    cout << hammingWeight(n) << endl;
    n = 128;
    cout << hammingWeight(n) << endl;
}