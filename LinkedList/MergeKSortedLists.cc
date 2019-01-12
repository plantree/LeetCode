#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    ListNode *cur1 = l1, *cur2 = l2;
    ListNode *head = new ListNode(-1), *cur = head;
    while (cur1 && cur2) {
        if (cur1->val <= cur2->val) {
            cur->next = cur1;
            cur1 = cur1->next;
        } else {
            cur->next = cur2;
            cur2 = cur2->next;
        }
        cur = cur->next;
    }
    if (!cur1) {
        cur->next = cur2;
    } else {
        cur->next = cur1;
    }
    return head->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }
    int len = lists.size();
    while (len > 1) {
        for (int i = 0; i < len/2; ++i) {
            if (lists[i] != lists[len-i-1]) {
                lists[i] = mergeTwoLists(lists[i], lists[len-i-1]);
            }
            len = (len + 1) / 2;
        }
    }
    return lists[0];
}
