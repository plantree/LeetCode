#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
        return nullptr;
    }
    ListNode *curA = headA;
    while (curA->next) {
        curA = curA->next;
    }
    curA->next = headB;
    ListNode *fast = headA, *slow = headB;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    // 说明无环
    if (!fast || !fast->next) {
        curA->next = nullptr;
        return nullptr;
    }
    // 说明有环
    slow = headA;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    curA->next = nullptr;
    return fast;
}