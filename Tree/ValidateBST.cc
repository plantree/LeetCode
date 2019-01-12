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

bool isValidBST(TreeNode *root, long min, long max) {
    if (!root) {
        return true;
    }
    if (root->val <= min || root->val >= max) {
        return false;
    }
    return isValidBST(root->left, min, root->val) &&
           isValidBST(root->right, max, root->val);
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
}

int main() {
    vector<int> nodes = {2, 1, 3};
    TreeNode *root = createTree(nodes, 0);
    cout << isValidBST(root) << endl;
    nodes = {5, 1, 4, 3, 6};
    root = createTree(nodes, 0);
    cout << isValidBST(root) << endl;
}
