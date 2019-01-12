#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

// top to bottom
/*
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    vector<int> level;
    queue<TreeNode*> curQ, nextQ;
    curQ.push(root);
    while (!curQ.empty()) {
        TreeNode *curNode = curQ.front();
        curQ.pop();
        level.push_back(curNode->val);
        if (curNode->left) {
            nextQ.push(curNode->left);
        }
        if (curNode->right) {
            nextQ.push(curNode->right);
        }
        if (curQ.empty()) {
            res.push_back(level);
            level.clear();
            curQ = nextQ;
            // clear
            while (!nextQ.empty()) {
                nextQ.pop();
            }
        }
    }
    return res;
}*/

// bottom to top
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    vector<int> level;
    queue<TreeNode*> curQ, nextQ;
    curQ.push(root);
    while (!curQ.empty()) {
        TreeNode *curNode = curQ.front();
        curQ.pop();
        level.push_back(curNode->val);
        if (curNode->left) {
            nextQ.push(curNode->left);
        }
        if (curNode->right) {
            nextQ.push(curNode->right);
        }
        if (curQ.empty()) {
            res.insert(res.cbegin(), level);
            level.clear();
            curQ = nextQ;
            // clear
            while (!nextQ.empty()) {
                nextQ.pop();
            }
        }
    }
    return res;
}


int main() {
    vector<int> nodes = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = createTree(nodes, 0);
    auto order = levelOrder(root);
    for (auto level : order) {
        for (auto item : level) {
            cout << item << " ";
        }
        cout << endl;
    }
}
