#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> helper(string s, vector<string>& wordDict, 
                        unordered_map<string, vector<string>>& m){
    if (m.count(s)) {
        return m[s];
    }
    if (s.empty()) {
        return {""};
    }
    vector<string> res;
    for (string word : wordDict) {
        if (s.substr(0, word.length()) != word) {
            continue;
        }
        vector<string> rem = helper(s.substr(word.length()), wordDict, m);
        for (string str : rem) {
            res.push_back(word + (str.empty() ? "" : " ") + str);
        }
    }
    m[s] = res;
    return res;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, vector<string>> m;
    return helper(s, wordDict, m);
}

int main() {
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    auto result = wordBreak(s, wordDict);
    for (auto item : result) {
        cout << item << endl;
    }
}