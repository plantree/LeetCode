#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculate(string s) {
    int res = 0, num = 0, n = s.size();
    char op = '+';
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            num = num * 10 + c - '0';
        }
        // 参与计算的时机
        if ((c < '0' && c != ' ') || i == n - 1) {
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
    cout << calculate("3+2*2") << endl;
    cout << calculate("3/2") << endl;
    cout << calculate("3+5/2") << endl;
}