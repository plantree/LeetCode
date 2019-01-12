#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

// solution 1
RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) {
        return nullptr;
    }
    RandomListNode *res = new RandomListNode(head->label);
    RandomListNode *node = res;
    RandomListNode *cur = head->next;
    map<RandomListNode*, RandomListNode*> m;
    m[head] = res;
    while (cur) {
        RandomListNode *temp = new RandomListNode(cur->label);
        node->next = temp;
        m[cur] = temp;
        node = node->next;
        cur = cur->next;
    }
    node = res;
    cur = head;
    while (node) {
        node->random = m[cur->random];
        node = node->next;
        cur = cur->next;
    }
    return res;
}

// solution 2
RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) {
        return nullptr;
    }
    RandomListNode *cur = head;
    while (cur) {
        RandomListNode *node = new RandomListNode(cur->label);
        node->next = cur->next;
        cur->next = node;
        cur = node->next;
    }
    cur = head;
    while (cur) {
        if (cur->random) {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }
    cur = head;
    RandomListNode *res = head->next;
    while (cur) {
        RandomListNode *temp = cur->next;
        cur->next = temp->next;
        if (temp->next) {
            temp->next = temp->next->next;
        }
        cur = cur->next;
    }
    return res;
}