#include <iostream>
#include <vector>

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

int min(int x, int y) {
    return x < y ? x : y;
}

int minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    if (root->left == nullptr) {
        return minDepth(root->right) + 1;
    } else if (root->right == nullptr) {
        return minDepth(root->left) + 1;
    } else {
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
}

int main() {
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* T = createTree(nums, 0);
    cout << minDepth(T) << endl;
}