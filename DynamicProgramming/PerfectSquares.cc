#include <iostream>
#include <vector>

using namespace std;

int min(int x, int y) {
    return x < y ? x : y;
}

int numSquares(int n) {
    vector<int> dp(n + 1, INT16_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; i + j * j <= n; ++j) {
            dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
        }
    }
    return dp[n];
}

int main() {
    int n = 12;
    cout << numSquares(n) << endl;
    n = 13;
    cout << numSquares(n) << endl;
}