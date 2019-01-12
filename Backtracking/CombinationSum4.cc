#include <iostream>
#include <vector>

using namespace std;

// solution 1
/*
void helper(vector<int>& nums, int target, int& count) {
    if (target == 0) {
        count++;
        return;
    } else if (target < 0) {
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        helper(nums, target-nums[i], count);
    }
}

int combinationSum4(vector<int>& nums, int target) {
    int count = 0;
    helper(nums, target, count);
    return count;
}*/

// solution 2
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    dp[0] = 1;
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= target; ++i) {
        for (auto item : nums) {
            if (i < item) {
                break;
            }
            dp[i] += dp[i-item];
        }
    }
    return dp.back();
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << combinationSum4(nums, 4) << endl;
}