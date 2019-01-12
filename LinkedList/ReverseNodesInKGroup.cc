#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *first = new ListNode(-1), *pre = first, *cur = pre;
    first->next = head;
    int num = 0;
    while (cur = cur->next) {
        ++num;
    }
    while (num >= k) {
        cur = pre->next;
        for (int i = 1; i < k; ++i) {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        pre = cur;
        num -= k;
    }
    return first->next;
}