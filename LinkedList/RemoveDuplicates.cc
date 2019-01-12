#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head) {
        return head;
    }
    ListNode *cur = head, *pre = head;
    while (cur->next) {
        cur = cur->next;
        if (pre->val == cur->val) {
            pre->next = cur->next;
        } else {
            pre = pre->next;
        }
    }
    return head;
}