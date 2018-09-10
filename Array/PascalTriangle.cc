#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    vector<int> last;
    if (numRows == 0) {
        return triangle;
    }
    for (int i = 0; i < numRows; ++i) {
        // 向量初始化
        vector<int> temp(i+1, 1);
        for (int j = 1; j < i; ++j) {
            temp[j] = last[j-1] + last[j];
        }
        triangle.push_back(temp);
        last = temp;        
    }
    return triangle;
}

int main() {
    auto triangle = generate(10);
    for (auto line : triangle) {
        for (auto item : line) {
            cout << item << " ";
        }
        cout << endl;
    }
}