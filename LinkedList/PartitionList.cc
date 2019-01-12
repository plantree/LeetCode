#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* partition(ListNode* head, int x) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *first = new ListNode(-1),
             *second = new ListNode(-1);
    ListNode *cur = head, *p1 = first, *p2 = second;
    while (cur) {
        if (cur->val < x) {
            p1->next = cur;
            p1 = p1->next;
        } else {
            p2->next = cur;
            p2 = p2->next;
        }
        cur = cur->next;
    }
    p2->next = nullptr;
    p1->next = second->next;
    return first->next;
}