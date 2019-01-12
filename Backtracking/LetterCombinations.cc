#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(string digits, vector<string> dict, int level, string last, vector<string>& res) {
    if (level == digits.size()) {
        res.push_back(last);
        return;
    }
    string str = dict[digits[level]-'0'-2];
    for (int i = 0; i < str.size(); ++i) {
        helper(digits, dict, level+1, last+string(1, str[i]), res);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) {
        return res;
    }
    vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    helper(digits, dict, 0, "", res);
    return res;
}

int main() {
    auto results = letterCombinations("23");
    for (auto result : results) {
        cout << result << " ";
    }
    cout << endl;
}