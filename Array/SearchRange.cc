#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(int A[], int n, int target) {
    vector<int> res = {-1, -1};
    if (n == 0) {
        return res;
    }
    int left = 0,
        right = n - 1;
    // first occurs
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1; 
        }
    }
    if (left < n && A[left] == target) {
        res[0] = left;
        // last occurs
        right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        res[1] = right;
        return res;
    } else {
        return res;
    }
}

int main() {
    int A[] = {5, 7, 7, 8, 8, 10};
    auto res = searchRange(A, 6, 8);
    cout << res[0] << ", " << res[1] << endl;
    res = searchRange(A, 6, 9);
    cout << res[0] << ", " << res[1] << endl;
}