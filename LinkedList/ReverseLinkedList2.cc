#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *first = new ListNode(-1);
    first->next = head;
    ListNode *cur = first, *pre, *front, *last;
    for (int i = 1; i <= m - 1; ++i) {
        cur = cur->next;
    }
    pre = cur;
    last = cur->next;
    for (int i = m; i <= n; ++i) {
        cur = pre->next;
        pre->next = cur->next;
        cur->next = front;
        front = cur;
    }
    cur = pre->next;
    pre->next = front;
    last->next = cur;
    return first->next;
}