#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculate(string s) {
    int n = s.size(), num = 0, res = 0;
    char op = '+';
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            num = 10 * num + c - '0';
        } else if (c == '(') {
            // 递归解决
            int j = i, cnt = 0;
            for (; i < n; ++i) {
                if (s[i] == '(') {
                    ++cnt;
                }
                if (s[i] == ')') {
                    --cnt;
                }
                if (cnt == 0) {
                    break;
                }
            }
            num = calculate(s.substr(j+1, i-j-1));
        }
        if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
            if (op == '+') {
                st.push(num);
            }
            if (op == '-') {
                st.push(-num);
            }
            if (op == '*' || op == '/') {
                int temp = (op == '*') ? st.top() * num : st.top() / num;
                st.pop();
                st.push(temp);
            }
            op = c;
            num = 0;
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main() {
    cout << calculate("1 + 1") << endl;
    cout << calculate("2*(5+5*2)/3+(6/2+8)") << endl;
}