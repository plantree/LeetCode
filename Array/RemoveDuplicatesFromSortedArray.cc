#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int temp = nums[0];
    for (auto begin = ++nums.begin(); begin != nums.end(); ) {
        if (*begin == temp) {
            begin = nums.erase(begin);
        } else {
            temp = *begin;
            begin++;
        }
    }
    return nums.size();
}

int removeDuplicates(int A[], int n) {
    if (n == 0) {
        return 0;
    }
    int i = 0, j = 0;
    for (i = 1; i < n; ++i) {
        if (A[i] == A[j]) {
            continue;
        }
        j++;
        A[j] = A[i];
    }
    return j + 1;
}

int main() {
    //vector<int> nums = {1, 1, 1};
    //int len = removeDuplicates(nums);
    int nums[] = {1, 1, 2};
    int len = removeDuplicates(nums, 3);
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
}