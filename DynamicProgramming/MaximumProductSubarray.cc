#include <iostream>
#include <vector>

using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int maxProduct(vector<int>& nums) {
    int res = 0,
        maxProduct = 1,
        minProduct = 1;
    if (nums.empty()) {
        return res;
    }
    res = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        int t = maxProduct;
        maxProduct = max(max(maxProduct * nums[i], nums[i]), minProduct * nums[i]);
        minProduct = min(min(minProduct * nums[i], nums[i]), t * nums[i]);
        res = max(res, maxProduct);
    }
    return res;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << maxProduct(nums) << endl;
    nums = {-2, 0, 1};
    cout << maxProduct(nums) << endl;
}