#include <iostream>
#include <vector>

using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}

int jump(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int res = 0, n = nums.size(), i = 0, cur = 0;
    while (cur < n-1) {
        res++;
        int pre = cur;
        for (; i <= pre; ++i) {
            cur = max(cur, i+nums[i]);
        }
        if (pre == cur) {
            return - 1;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums) << endl;
}