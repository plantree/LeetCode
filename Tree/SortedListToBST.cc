#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) {
        return nullptr;
    }
    if (!head->next) {
        return new TreeNode(head->val);
    }
    // 快慢指针初始化
    ListNode *slow = head,
             *fast = head,
             *last = slow;
    while (fast->next && fast->next->next) {
        last = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    last->next = nullptr;
    TreeNode *cur = new TreeNode(slow->val);
    if (head != slow) {
        cur->left = sortedListToBST(head);
    }
    cur->right = sortedListToBST(fast);
    return cur;
}
