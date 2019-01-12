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

int main() {
   vector<int> heights = {2, 1, 5, 6, 2, 3};
   int maxArea = largestRectangleArea(heights);
   cout << maxArea << endl;
}