#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1);
    // 第二行开始有真正的计算
    for (int i = 2; i < rowIndex + 1; ++i) {
        for (int j = i - 1; j >= 1; --j) {
            row[j] = row[j] + row[j - 1];
        }
    }
    return row;
}

int main() {
    auto row = getRow(3);
    for (auto item : row) {
        cout << item << " ";
    }
    cout << endl;
}