#include <iostream>
#include <vector>

using namespace std;

int min(int x, int y) {
    return x < y ? x : y;
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) {
        return 0;
    }
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else if (i == 0 && j > 0) {
                dp[i][j] = dp[i][j-1] + grid[i][j];
            } else if (i > 0 && j == 0) {
                dp[i][j] = dp[i-1][j] + grid[i][j];
            } else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
    }
    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid) << endl;
}