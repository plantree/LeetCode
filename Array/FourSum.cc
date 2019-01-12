#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > result;
    if (nums.size() < 4) {
        return result;
    }

    // sort
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 3; ++i) {
        // 跳过重复
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        for (int j = i + 1; j < nums.size() - 2; ++j) {
            // 跳过重复
            if (j > i + 1 && nums[j] == nums[j-1]) {
                continue;
            }
            int start = j + 1,
                end = nums.size() - 1;
            while (start < end) {
                int tempSum = nums[i] + nums[j] + nums[start] + nums[end];
                if (tempSum == target) {
                    result.push_back({nums[i], nums[j], nums[start], nums[end]});
                    start++;
                    while (nums[start-1] == nums[start]) {
                        start++;
                    }
                    end--;
                    while (nums[end+1] == nums[end]) {
                        end--;
                    }
                } else if (tempSum > target) {
                    end--;
                } else {
                    start++;
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    auto results = fourSum(nums, 0);
    for (auto result : results) {
        for (auto item : result) {
            cout << item << " ";
        }
        cout << endl;
    }
}