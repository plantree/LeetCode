#include <iostream>
#include <vector>

using namespace std;

int Max(int x, int y) {
    return x > y ? x : y;
}

int Min(int x, int y) {
    return x < y ? x : y;
}

int maxProfit(vector<int>& prices) {
    if (prices.empty() || prices.size() == 1) {
        return 0;
    }
    vector<int> left(prices.size()),
                right(prices.size());

    // DP from left to right
    left[0] = 0;
    int min = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        min = Min(min, prices[i]);
        left[i] = Max(left[i-1], prices[i]-min);
    }

    // DP from right to left
    right[prices.size()-1] = 0;
    int max = prices[prices.size() - 1];
    for (int i = prices.size() - 2; i >= 0; --i) {
        max = Max(max, prices[i]);
        right[i] = Max(right[i+1], max-prices[i]);
    }

    int profit = 0;
    for (int i = 0; i < prices.size(); ++i) {
        profit = Max(profit, left[i] + right[i]);
    }

    return profit;
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl;
}