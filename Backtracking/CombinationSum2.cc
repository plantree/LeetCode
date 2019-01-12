#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int> candidates, int target, vector<int> last, int start, vector<vector<int>>& res) {
    if (target < 0) {
        return;
    } else if (target == 0) {
        res.push_back(last);
        return;
    }
    for (int i = start; i < candidates.size(); ++i) {
        if (i > start && candidates[i] == candidates[i-1]) {
            continue;
        }
        last.push_back(candidates[i]);
        helper(candidates, target-candidates[i], last, i+1, res);
        last.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, {}, 0, res);
    return res;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    auto solutions = combinationSum2(candidates, 8);
    for (auto solution : solutions) {
        for (auto item : solution) {
            cout << item << " ";
        }
        cout << endl;
    }
}
