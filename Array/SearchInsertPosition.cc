#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    if (nums.empty()) {
        return 0;
    }
    if (target <= nums[0]) {
        return 0;
    }
    if (target > nums.back()) {
        return nums.size();
    }
    int left = 0,
        right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    if (nums[left] > target) {
        return left;
    } else {
        return (left + 1);
    }
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    cout << searchInsert(nums, 5) << endl;
    cout << searchInsert(nums, 2) << endl;
    cout << searchInsert(nums, 7) << endl;
}