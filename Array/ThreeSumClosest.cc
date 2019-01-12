#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int x) {
    if (x > 0) {
        return x;
    } else {
        return -x;
    }
}
int threeSumClosest(vector<int>& nums, int target) {
    int closestSum = 9999;
    int tempSum;
    
    if (nums.size() < 1) {
        return 0;
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
        int a = nums[i];
        int start = i + 1,
            end = nums.size() - 1;
        while (start < end) {
            int b = nums[start],
                c = nums[end];
            tempSum = a + b + c - target;
            if (abs(tempSum) < abs(closestSum)) {
                closestSum = tempSum;
            }
            if (tempSum == 0) {
                return target;
            } else if (tempSum > 0) {
                end--;
            } else {
                start++;
            }  
        }
    }
    return closestSum + target;
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    auto result = threeSumClosest(nums, 1);
    cout << "closet sum: " << result << endl;
}