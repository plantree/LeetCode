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

bool isSymmetric(TreeNode *left, TreeNode *right) {
    if (!left && !right) {
        return true;
    }
    if ((left && !right) || (!left && right) || (left->val != right->val)) {
        return false;
    }
    return isSymmetric(left->left, right->right) && 
            isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode *root) {
    if (!root) {
        return true;
    }
    return isSymmetric(root->left, root->right);
}

int main() {
    vector<int> nodes = {1, 2, 2, 3, 4, 4, 3};
    TreeNode *root = createTree(nodes, 0);
    cout << isSymmetric(root) << endl;

    nodes = {1, 2, 2, -1, 3, -1, 3};
    root = createTree(nodes, 0);
    cout << isSymmetric(root) << endl;

    nodes = {1, 2, 3, 3, -1, 2, -1};
    root = createTree(nodes, 0);
    cout << isSymmetric(root) << endl;

    nodes = {5, 4, 1, -1, 1, -1, 4, 2, -1, 2, -1};
    root = createTree(nodes, 0);
    cout << isSymmetric(root) << endl;
}