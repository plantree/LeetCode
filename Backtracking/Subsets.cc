#include <iostream>
#include <vector>

using namespace std;

// solution 1
/*
void helper(vector<int>& nums, int start, vector<int> last, vector<vector<int>>& res) {
    res.push_back(last);
    for (int i = start; i < nums.size(); ++i) {
        last.push_back(nums[i]);
        helper(nums, i+1, last, res);
        last.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.empty()) {
        return res;
    }
    sort(nums.begin(), nums.end());
    helper(nums, 0, {}, res);
    return res;
}*/

// solution 2
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res(1);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        int size = res.size();
        for (int j = 0; j < size; ++j) {
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto results = subsets(nums);
    for (auto result : results) {
        for (auto item : result) {
            cout << item << " ";
        }
        cout << endl;
    }
}