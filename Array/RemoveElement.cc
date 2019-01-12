#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    for (auto begin = nums.begin(); begin != nums.end(); ) {
        if (*begin == val) {
            begin = nums.erase(begin);
        } else {
            ++begin;
        }
    }
    return nums.size();
}

int removeElement(int A[], int n, int elem) {
    int i = 0, j = 0;
    for (i = 0; i < n; ++i) {
        if (A[i] == elem) {
            continue;
        }
        A[j] = A[i];
        j++;
    }
    return j;
}

int main() {
    /*
    vector<int> nums = {3, 2, 2, 3};
    int len = removeElement(nums, 3);
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }*/
    int A[] = {3, 2, 2, 3};
    int len = removeElement(A, 4, 3);
    for (int i = 0; i < len; ++i) {
        cout << A[i] << " ";
    }

}
