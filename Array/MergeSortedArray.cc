#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int count = m + n;
    int i = m - 1, j = n - 1;
    while (count > 0) {
        count--;
        
        if (i >= 0 && j >= 0) {
            if (nums2[j] > nums1[i]) {
                nums1[count] = nums2[j];
                j--;
            } else {
                nums1[count] = nums1[i];
                i--;
            }
        } else if (j >= 0) {
            nums1[count] = nums2[j];
            j--;
        } else if (i >= 0) {
            nums1[count] = nums1[i];
            i--;
        }
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0},
                nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    for (auto item : nums1) {
        cout << item << " ";
    }
    cout << endl;
}