#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

// 完全二叉树
/*
void connect(TreeLinkNode *root) {
    if (!root) {
        return;
    }
    if (root->left) {
        root->left->next = root->right;
    }
    if (root->right) {
        root->right->next = root->next ? root->next->left : nullptr;
    }
    connect(root->left);
    connect(root->right);
}*/

// 普通二叉树
void connect(TreeLinkNode *root) {
    if (!root) {
        return;
    }
    TreeLinkNode *p = root->next;
    // 循环扫描直到非空
    while (p) {
        if (p->left) {
            p = p->left;
            break;
        }
        if (p->right) {
            p = p->right;
            break;
        }
        p = p->next;
    }
    if (root->right) {
        root->right->next = p;
    }
    if (root->left) {
        root->left->next = root->right ? root->right : nullptr;
    }
    connect(root->right);
    connect(root->left);
}