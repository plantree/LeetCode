#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    if (nums.size() == 0 || nums.size() == 1) {
        return 0;
    }
    int left = 0,
        right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid+1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << findPeakElement(nums) << endl;
    nums = {1, 2, 1, 3, 5, 6, 4};
    cout << findPeakElement(nums) << endl;
}