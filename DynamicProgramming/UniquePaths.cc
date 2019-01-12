#include <iostream>

using namespace std;

int uniquePaths(int m, int n) {
    int dp[m][n];
    // 初始化dp, m x 1情况全为1
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }
    // 初始化dp, 1 x n情况全为1
    for (int j = 0; j < n; ++j) {
        dp[0][j] = 1;
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    int m = 3, n = 2;
    cout << uniquePaths(m, n) << endl;
    m = 7;
    n = 3;
    cout << uniquePaths(m, n) << endl;
}