#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// solution 1 (iteratively)
/*
ListNode* reverseList(ListNode* head) {
    if (!head) {
        return head;
    }
    ListNode *cur = head, *pre = head, *temp = head;
    while (cur->next) {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    cur->next = pre;
    head->next = nullptr;
    return cur;
}*/

// solution 2 (recursively)
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *p = head;
    head = reverseList(head->next);
    p->next->next = p;
    p->next = nullptr;
    return head;
}