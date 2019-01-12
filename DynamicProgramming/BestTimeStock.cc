#include <iostream>
#include <vector>

using namespace std;;

int max(int x, int y) {
    return x > y ? x : y;
}

int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    if (prices.empty() || prices.size() == 1) {
        return maxProfit;
    }
    int curPrice = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        int tempProfit = prices[i] - curPrice;
        if (tempProfit <= 0) {
            curPrice = prices[i];
        } else {
            maxProfit = max(maxProfit, tempProfit);
        }
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices) << endl;
    prices = {1, 2};
    cout << maxProfit(prices) << endl;
}