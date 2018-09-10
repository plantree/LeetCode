#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int temp = nums[0];
    int count = 0;
    for (auto begin = ++nums.begin(); begin != nums.end(); ) {
        if (*begin == temp) {
            count++;
            if (count >= 2) {
                begin = nums.erase(begin);
            } else {
                begin++;
            }
        } else {
            temp = *begin;
            count = 0;
            begin++;
        } 
    }
    return nums.size();
}

int removeDuplicates(int A[], int n) {
    if (n == 0) {
        return 0;
    }
    int i = 0, j = 0, count = 0;
    for (i = 1; i < n; ++i) {
        if (A[i] == A[j]) {
            count++;
            if (count < 2) {
                j++;
            }
        } else {
            j++;
            A[j] = A[i];
            count = 0;
        }
    }
    return j + 1;
}

int main() {
    /*vector<int> nums = {0, 1, 1, 1, 2, 2, 3};
    int len = removeDuplicates(nums);*/
    int nums[] = {0, 1, 1, 1, 2, 2, 3, 3, 3, 3};
    int len = removeDuplicates(nums, 10);
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
}