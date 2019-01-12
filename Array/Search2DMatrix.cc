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
    
    // soluion 1
    /*
    int left = 0,
        right = m - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (matrix[mid][0] < target) {
            left = mid + 1;
        } else if (matrix[mid][0] > target) {
            right = mid - 1;
        } else {
            return true;
        }
    }
    if (matrix[right][0] > target) {
        return binarySearch(matrix[right-1], target);
    } else {
        return binarySearch(matrix[right], target);
    }
    */

    // solution 2
    int row = 0,
        col = n - 1;
    while (row < m && col >= 0) {
        if (target > matrix[row][col]) {
            row++;
        } else if (target < matrix[row][col]) {
            col--;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,   3,  5,  7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}};
    cout << searchMatrix(matrix, 3) << endl;
}