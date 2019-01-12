#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int count = 0, 
        n = A.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ++m[A[i] + B[j]];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int target = -(C[i] + D[j]);
            count += m[target];
        }
    }
    return count;
}

int main() {
    vector<int> A = {1, 2},
                B = {-2,-1},
                C = {-1, 2},
                D = {0, 2};
    int count = fourSumCount(A, B, C, D);
    cout << count << endl;
}