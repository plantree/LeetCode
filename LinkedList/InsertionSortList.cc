#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *first = new ListNode(-1), *cur = first;
    while (head) {
        ListNode *t = head->next;
        cur = first;
        while (cur->next && cur->next->val <= head->val) {
            cur = cur->next;
        }
        head->next = cur->next;
        cur->next = head;
        head = t;
    }
    return first->next;
}