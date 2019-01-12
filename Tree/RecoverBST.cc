#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(vector<int> list, int start) {
    if (list[start] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(list[start]);

    // 构造左右子树
    int lnode = 2 * start + 1;
    int rnode = 2 * start + 2;
    if (lnode < list.size()) {
        root->left = createTree(list, lnode);
    } 
    
    if (rnode < list.size()) {
        root->right = createTree(list, rnode);
    } 
    return root;
}

void swap(int& x, int &y) {
    int t = x;
    x = y;
    y = t;
}

void recoverTree(TreeNode* root) {
    TreeNode *first = nullptr,
             *second = nullptr,
             *parent = nullptr;
    TreeNode *cur, *pre;
    cur = root;
    while (cur) {
        if (!cur->left) {
            if (parent && parent->val > cur->val) {
                if (!first) {
                    first = parent;
                }
                second = cur;
            }
            parent = cur;
            cur = cur->right;
        } else {
            pre = cur->left;
            while (pre->right && pre->right != cur) {
                pre = pre->right;
            }
            if (!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                if (parent->val > cur->val) {
                    if (!first) {
                        first = parent;
                    }
                    second = cur;
                }
                parent = cur;
                cur = cur->right;
            }
        }
    }
    if (first && second) {
        swap(first->val, second->val);
    } 
}

vector<int> MorrisTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    TreeNode *cur, *pre;
    cur = root;
    while (cur) {
        if (!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
        } else {
            pre = cur->left;
            while (pre->right && pre->right != cur) {
                pre = pre->right;
            }
            if (!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nodes = {1, 2, 3, 4, 5};
    TreeNode *root = createTree(nodes, 0);
    auto res = MorrisTraversal(root);
    for (auto item : res) {
        cout << item << " ";
    }
    cout << endl;
    
}



