#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode *start = new ListNode(-1);
    start->next = head;
    ListNode *cur = head, *pre = start;
    while (pre->next) {
        cur = pre->next;
        while (cur->next && cur->next->val == cur->val) {
           cur = cur->next;
        }
        if (cur != pre->next) {
            pre->next = cur->next;
        } else {
            pre = pre->next;
        }
    }
    return start->next;
}