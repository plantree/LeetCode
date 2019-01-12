#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode *first = new ListNode(-1), *pre = first, *cur = first;
    first->next = head;
    int num = 0;
    while (cur = cur->next) {
        ++num;
    }
    while (num >= 2) {
        cur = pre->next;
        ListNode *t = cur->next;
        cur->next = t->next;
        t->next = pre->next;
        pre->next = t;
        pre = cur;
        num -= 2;
    }
    return first->next;
}