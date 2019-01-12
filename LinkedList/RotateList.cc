#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) {
        return head;
    }
    int n = 1;
    ListNode *cur = head;
    // 计算链表长度
    while (cur->next) {
        cur = cur->next;
        n++;
    }

    k = n - k % n;
    
    // 连接成环
    cur->next = head;

    for (int i = 0; i < k; ++i) {
        cur = cur->next;
    }

    // 得到新的链头并断开环
    head = cur->next;
    cur->next = nullptr;
    return head;
}