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
            visited[i] = 1;
            last.push_back(nums[i]);
            helper(nums, visited, last, res);
            visited[i] = 0;
            last.pop_back();
            while (i < nums.size() - 1 && nums[i] == nums[i+1]) {
                ++i;
            }
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.empty()) {
        return res;
    }
    sort(nums.begin(), nums.end());
    vector<int> visited(nums.size());
    helper(nums, visited, {}, res);
    return res;
}

int main() {
    vector<int> nums = {1, 1, 2};
    auto results = permuteUnique(nums);
    for (auto result : results) {
        for (auto item : result) {
            cout << item << " ";
        }
        cout << endl;
    }
}