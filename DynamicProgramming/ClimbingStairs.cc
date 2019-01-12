#include <iostream>

using namespace std;

int climbStairs(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
    int res = 1,
        last = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = res;
        res += last;
        last = temp;
    }
    return res;
}

int main() {
    int n = 2;
    cout << climbStairs(n) << endl;
    n = 3;
    cout << climbStairs(n) << endl;
}