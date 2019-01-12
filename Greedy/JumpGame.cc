#include <iostream>
#include <vector>

using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}

// solution 1
/*
bool canJump(vector<int>& nums) {
    if (nums.empty()) {
        return true;
    }
    vector<int> dp(nums.size());
    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = max(dp[i-1], nums[i-1]) - 1;
        if (dp[i] < 0) {
            return false;
        }
    }
    return dp.back() >= 0;
}*/

// solution 2
bool canJump(vector<int>& nums) {
    if (nums.empty()) {
        return true;
    }
    int len = nums.size(), reach = 0;
    for (int i = 0; i < len; ++i) {
        if (i > reach || reach >= len-1) {
            break;
        }
        reach = max(reach, i + nums[i]);
    }
    return reach >= len-1;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << canJump(nums) << endl;
    nums = {3, 2, 1, 0, 4};
    cout << canJump(nums) << endl;
}