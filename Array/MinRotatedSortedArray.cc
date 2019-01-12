#include <iostream>
#include <vector>

using namespace std;

int min(int x, int y) {
    return x > y ? y : x;
}

int findMin(vector<int>& nums) {
    // O(n)
    /*
    int i = 0;
    for (i = 0; i < nums.size() - 1; ++i) {
        if (nums[i + 1] > nums[i]) {
            continue;
        } else {
            break;
        }
    }
    if (i == nums.size() - 1) {
        return nums[0];
    }
    if (nums[0] < nums[i + 1]) {
        return nums[0];
    } else {
        return nums[i + 1];
    }*/

    // O(logn)
    int left = 0,
        right = nums.size() - 1;
    if (nums[left] > nums[right]) {
        while (left != right - 1) {
            int mid = (left + right) / 2;
            if (nums[left] < nums[mid]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return nums[right];
    }
    return nums[0];
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int min = findMin(nums);
    cout << min << endl;
    nums = {1, 2};
    min = findMin(nums);
    cout << min << endl;
}