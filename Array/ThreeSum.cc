#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() < 1) {
        return {};
    }
    // 避免重复
    int temp = 1;

    // sort
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
        int a = nums[i];
        if (a > 0) {
            break;
        }
        if (a == temp) {
            continue;
        }
        temp = a;
        int start = i + 1, end = nums.size() - 1;
        while (start < end) {
            int b = nums[start],
                c = nums[end];
            if (a + b + c == 0) {
                result.push_back({a, b, c});
                start++;
                // 避免重复
                while ((nums[start-1] == nums[start])) {
                    start++;
                }
                end--;
                // 避免重复
                while ((nums[end+1] == nums[end])) {
                    end--;
                }
            } else if (a + b + c > 0) {
                end--;
            } else {
                start++;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-2,0,3,-1,4,0,3,4,1,1,1,-3,-5,4,0};
    auto results = threeSum(nums);
    for (auto result : results) {
        for (auto item : result) {
            cout << item << " ";
        }
        cout << endl;
    }
}