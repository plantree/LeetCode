#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>&nums, int target) {
    // solution 1 -> O(n*n)
    /*
    int len = nums.size();
    vector<int> result(2, 0);
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
    */

    // solution 2 -> O(n)
    unordered_map<int, int> m;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i) {
        int t = target - nums[i];
        if (m.count(t) && m[t] != i) {
            result.push_back(i);
            result.push_back(m[t]);
            break;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    auto result = twoSum(nums, 18);
    for (auto item : result) {
        cout << item << " ";
    }
    cout << endl;
}