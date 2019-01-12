#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    // solution 1
    /*
    int originSum = 0,
        realSum = 0;
    for (int i = 1; i <= nums.size(); ++i) {
        originSum += i;
    }
    for (int i = 0; i < nums.size(); ++i) {
        realSum += nums[i];
    }
    return originSum - realSum;
    */

    // solution 2
    int temp = 0;
    for (int i = 0; i <= nums.size(); ++i) {
        temp ^= i;
    }
    for (auto num : nums) {
        temp ^= num;
    }
    return temp;
}

int main() {
   vector<int> nums = {3, 0, 1};
   cout << missingNumber(nums) << endl;
   nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
   cout << missingNumber(nums) << endl;
}