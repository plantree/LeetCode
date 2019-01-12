#include <iostream>
#include <vector>

using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}

int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();

    if (len <= 1) {
        return 0;
    }

    if (k >= prices.size()) {
        return solveMaxProfit(prices);
    }
    
    int local[len][k+1];
    int global[len][k+1];
    memset(local, 0, len * (k+1) * sizeof(int));
    memset(global, 0, len * (k+1) * sizeof(int));
    for (int i = 1; i < len; ++i) {
        int diff = prices[i] - prices[i-1];
        for (int j = 1; j <= k; ++j) {
            local[i][j] = max(global[i-1][j-1]+max(diff, 0), local[i-1][j]+diff);
            global[i][j] = max(global[i-1][j], local[i][j]);
        }
    }
    return global[len-1][k];
}

int solveMaxProfit(vector<int>& prices) {
    int res = 0;
    for (int i = 1; i < prices.size(); ++i) {
        int tempProfit = prices[i] - prices[i-1];
        if (tempProfit > 0) {
            res += tempProfit;
        }
    }
    return res;
}

int main() {
    vector<int> prices = {2, 4, 1};
    cout << maxProfit(2, prices) << endl;
    prices = {3, 2, 6, 5, 0, 3};
    cout << maxProfit(2, prices) << endl;
}