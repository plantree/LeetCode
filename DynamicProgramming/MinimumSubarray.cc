#include <iostream>
#include <vector>

using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}

int maxSubArray(vector<int>& nums) {
    int maxSum = 0;
    int sum = 0;
    if (nums.empty()) {
        return maxSum;
    }
    maxSum = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
}