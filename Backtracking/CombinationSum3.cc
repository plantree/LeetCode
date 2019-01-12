#include <iostream>
#include <vector>

using namespace std;

void helper(int k, int n, vector<int> last, int start, vector<vector<int>>& res) {
    if (last.size() == k && n == 0) {
        res.push_back(last);
        return;
    }
    if (last.size() > k || n < 0) {
        return;
    }
    for (int i = start; i <= 9; ++i) {
        last.push_back(i);
        helper(k, n-i, last, i+1, res);
        last.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    helper(k, n, {}, 1, res);
    return res;
}

int main() {
    auto solutions = combinationSum3(3, 9);
    for (auto solution : solutions) {
        for (auto item : solution) {
            cout << item << " ";
        }
        cout << endl;
    }
}