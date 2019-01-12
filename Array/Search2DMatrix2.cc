#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int>& nums, int target) {
    int left = 0,
        right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            return true;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // 空值情况的排除
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return false;
    }

    int m = matrix.size(),
        n = matrix[0].size();
    if (target < matrix[0][0] || target > matrix[m-1][n-1]) {
        return false;
    }

    // solution 1
    /*
    bool flag = false;
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == target) {
            flag = true;
            break;
        } else if (matrix[i][0] < target) {
            flag = binarySearch(matrix[i], target);
            if (flag == true) {
                break;
            }
        } else {
            break;
        }
    }
    return flag;*/

    // solution 2
    int row = m - 1,
        col = 0;
    while (row >= 0 && col < n) {
        if (matrix[row][col] > target) {
            row--;
        } else if (matrix[row][col] < target) {
            col++;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,   4,  7, 11, 15},
                                  {2,   5,  8, 12, 19},
                                  {3,   6,  9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    cout << searchMatrix(matrix, 5) << endl;
    cout << searchMatrix(matrix, 20) << endl;
}