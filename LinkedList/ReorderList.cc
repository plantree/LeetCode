#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void reorderList(ListNode* head) {
    if (!head || !head->next) {
        return;
    }
    // 找到右半部分
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *right = slow->next;
    slow->next = nullptr;
    ListNode *cur = right, *pre = nullptr;

    // 翻转右半部分
    while (cur) {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    right = pre;

    // 合并
    while (head && right) {
        ListNode *next = head->next;
        head->next = right;
        right = right->next;
        head->next->next = next;
        head = next;
    }
}