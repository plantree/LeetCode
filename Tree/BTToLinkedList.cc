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

void flatten(TreeNode* root) {
    if (!root) {
        return;
    }
    if (root->left) {
        flatten(root->left);
    }
    if (root->right) {
        flatten(root->right);
    }
    TreeNode *temp = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (root->right) {
        root = root->right;
    }
    root->right = temp;
}

int main() {
    vector<int> nodes = {1, 2, 5, 3, 4, -1, 6};
    TreeNode *root = createTree(nodes, 0);
    flatten(root);
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

