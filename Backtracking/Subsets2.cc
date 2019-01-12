#include <iostream>
#include <vector>

using namespace std;

// solution 1
/*
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res(1);
    if (nums.empty()) {
        return res;
    }
    sort(nums.begin(), nums.end());
    int oldSize = 1;
    for (int i = 0; i < nums.size(); ++i) {
        int size = res.size();
        if (i == 0 || nums[i] != nums[i-1]) {
            oldSize = size;
        } 
        for (int j = size-oldSize; j < size; ++j) {
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
        }
    }
    return res;
}*/

// solution 2
void helper(vector<int>& nums, int start, vector<int> last, vector<vector<int>>& res) {
    res.push_back(last);
    for (int i = start; i < nums.size(); ++i) {
        last.push_back(nums[i]);
        helper(nums, i+1, last, res);
        last.pop_back();
        while (i + 1 < nums.size() && nums[i+1] == nums[i]) {
            ++i;
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.empty()) {
        return res;
    }
    sort(nums.begin(), nums.end());
    helper(nums, 0, {}, res);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 2};
    auto results = subsetsWithDup(nums);
    for (auto result : results) {
        for (auto item : result) {
            cout << item << " ";
        }
        cout << endl;
    }
}