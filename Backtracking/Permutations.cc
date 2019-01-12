#include <iostream>
#include <vector>

using namespace std;

void helper(vector<int>& nums, vector<int> visited, vector<int> last, vector<vector<int>>& res) {
    if (last.size() == nums.size()) {
        res.push_back(last);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i] == 0) {
            last.push_back(nums[i]);
            visited[i] = 1;
            helper(nums, visited, last, res);
            visited[i] = 0;
            last.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> visited(nums.size());
    if (nums.empty()) {
        return res;
    }
    helper(nums, visited, {}, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto results = permute(nums);
    for (auto result : results) {
        for (auto item : result) {
            cout << item << " ";
        }
        cout << endl;
    }
}