#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
    if (ratings.empty()) {
        return 0;
    }
    vector<int> candys(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); ++i) {
        if (ratings[i] > ratings[i-1]) {
            candys[i] = candys[i-1] + 1;
        }
    }

    for (int i = ratings.size()-2; i >= 0; --i) {
        if (ratings[i] > ratings[i+1] && candys[i] <= candys[i+1]) {
            candys[i] = candys[i+1] + 1;
        }
    }
    int count = 0;
    for (auto candy : candys) {
        count += candy;
    }
    return count;
}

int main() {
    vector<int> ratings = {1, 0, 2};
    cout << candy(ratings) << endl;
    ratings = {1, 2, 2};
    cout << candy(ratings) << endl;
}