#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.length()+1);
    dp[0] = true;
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordSet.count(s.substr(j, i-j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreak(s, wordDict) << endl;
    s = "applepenapple";
    wordDict = {"apple", "pen"};
    cout << wordBreak(s, wordDict) << endl;
    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout << wordBreak(s, wordDict) << endl;
}