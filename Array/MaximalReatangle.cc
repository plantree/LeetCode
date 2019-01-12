#include <iostream>
#include <vector>

using namespace std;

int min(int x, int y) {
    return x > y ? y : x;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int largestRectangleArea(vector<int>& heights) {
    if (heights.size() == 0) {
        return 0;
    }
    int res = 0;
    for (int i = 0; i < heights.size(); ++i) {
        if (i + 1 < heights.size() && heights[i] <= heights[i+1]) {
            continue;
        }
        int minH = heights[i];
        for (int j = i; j >= 0; --j) {
            minH = min(minH, heights[j]);
            int area = minH * (i - j + 1);
            res = max(res, area);
        }
    }
    return res;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int res = 0;
    vector<int> heights;
    for (int i = 0; i < matrix.size(); ++i) {
        heights.resize(matrix[i].size());
        for (int j = 0; j < matrix[i].size(); ++j) {
            heights[j] = matrix[i][j] == '0' ? 0 : (1 + heights[j]);
        }
        res = max(res, largestRectangleArea(heights));
    }
    return res;
}

int main() {
    vector<vector<char>> matrix = { {'1','0','1','0','0'}, 
                                    {'1','0','1','1','1'},
                                    {'1','1','1','1','1'}, 
                                    {'1','0','0','1','0'}};
    int maxRec = maximalRectangel(matrix);
    cout << maxRec << endl;
    
}