#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1) {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        s2.push(l2->val);
        l2 = l2->next;
    }
    int sum = 0;
    ListNode *temp = new ListNode(0);
    while (!s1.empty() || !s2.empty()) {
        if (!s1.empty()) {
            sum += s1.top();
            s1.pop();
        }
        if (!s2.empty()) {
            sum += s2.top();
            s2.pop();
        }
        temp->val = sum % 10;
        ListNode *head = new ListNode(sum / 10);
        head->next = temp;
        temp = head;
        sum /= 10;
    }
    return temp->val == 0 ? temp->next : temp;
}