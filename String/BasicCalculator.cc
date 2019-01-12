#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculate(string s) {
    int res = 0, sign = 1, n = s.size();
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c >= '0' && c <='9') {
            int num = 0;
            // 可能是多位数
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                num = 10 * num + s[i++] - '0';
            }
            res += sign * num;
            i--;
        } else if (c == '+') {
            sign = 1;
        } else if (c == '-') {
            sign = -1;
        } else if (c == '(') {
            // 及时保存中间结果
            st.push(res);
            st.push(sign);
            res = 0;
            sign = 1;
        } else if (c == ')') {
            res *= st.top();
            st.pop();
            res += st.top();
            st.pop();
        }
    }
    return res;
}

int main() {
    cout << calculate("1 + 1") << endl;
    cout << calculate("2-1 + 2") << endl;
    cout << calculate("(1+(4+5+2)-3+(6+8)") << endl;
}