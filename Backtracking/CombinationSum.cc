#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int>& candidates, int target, vector<int> last, int start, vector<vector<int>>& res) {
    if (target < 0) {
        return;
    } else if (target == 0) {
        res.push_back(last);
        return;
    }
    for (int i = start; i < candidates.size(); ++i) {
        last.push_back(candidates[i]);
        helper(candidates, target-candidates[i], last, i, res);
        last.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, {}, 0, res);
    return res;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    auto solutions = combinationSum(candidates, 7);
    for (auto solution : solutions) {
        for (auto item : solution) {
            cout << item << " ";
        }
        cout << endl;
    }
}