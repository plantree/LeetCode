#include <iostream>
#include <vector>

using namespace std;

void helper(int n, int k, int layer, vector<int>& out, vector<vector<int>>& res) {
    if (out.size() == k) {
        res.push_back(out);
    }
    for (int i = layer; i <= n; ++i) {
        out.push_back(i);
        helper(n, k, i + 1, out, res);
        out.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> out;
    helper(n, k, 1, out, res);
    return res;
}

int main() {
    int n = 4, k = 2;
    auto res = combine(n, k);
    for (auto items : res) {
        for (auto item : items) {
            cout << item << " ";
        }
        cout << endl;
    }
}