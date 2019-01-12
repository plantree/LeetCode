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

int max(int x, int y) {
    return x > y ? x : y;
}

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8};
    TreeNode* T = createTree(nums, 0);
    cout << maxDepth(T) << endl;
    nums = {3, 9, 20, -1, -1, 15, 7};
    T = createTree(nums, 0);
    cout << maxDepth(T) << endl;
}