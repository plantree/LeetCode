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

bool hasPathSum(TreeNode* root, int sum) {
    if (!root) {
        return false;
    }
    if (root->val == sum && !root->left && !root->right) {
        return true;
    } else {
        return hasPathSum(root->left, sum-root->val) || 
               hasPathSum(root->right, sum-root->val);
    }
}

int main() {
    vector<int> nodes = {5, 4, 8, 11, -1, 13, 4, 7, 2};
    TreeNode *root = createTree(nodes, 0);
    cout << hasPathSum(root, 22) << endl;
}