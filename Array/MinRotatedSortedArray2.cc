#include <iostream>
#include <vector>

using namespace std;

int min(int x, int y) {
    return x > y ? y : x;
}

int findMin(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int left = 0,
        right = nums.size() - 1;
    while (left < right - 1) {
        if (nums[left] < nums[right]) {
            return nums[left];
        }
        int mid = (left + right) / 2;
        if (nums[left] < nums[mid]) {
            left = mid;
        } else if (nums[left] > nums[mid]) {
            right = mid;
        } else {
            left++;
        }
    }
    return min(nums[left], nums[right]);
}

int main() {
    vector<int> nums = {10, 1, 10, 10, 10};
    int min = findMin(nums);
    cout << min << endl;
    nums = {2,2,2,0,1};
    min = findMin(nums);
    cout << min << endl;
}