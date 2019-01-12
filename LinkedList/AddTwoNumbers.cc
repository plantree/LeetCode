#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *first = new ListNode(-1);
    ListNode *p1 = l1, *p2 = l2, *p3 = first;
    // 存储进位
    int flag = 0;
    while (p1 && p2) {
        p3->next = new ListNode((p1->val + p2->val + flag) % 10);
        flag = (p1->val + p2->val + flag) <= 9 ? 0 : 1;
        p1 = p1->next;
        p2 = p2->next;
        p3 = p3->next;
    }
    ListNode *cur;
    if (p1) {
        cur = p1;
    } else if (p2) {
        cur = p2;
    } else {
        if (flag) {
            p3->next = new ListNode(1);
        }
        return first->next;
    }
    while (cur) {
        p3->next = new ListNode((cur->val + flag) % 10);
        flag = (cur->val + flag) <= 9 ? 0 : 1;
        cur = cur->next;
        p3 = p3->next;
    }
    if (flag) {
        p3->next = new ListNode(1);
    }
    return first->next;
}