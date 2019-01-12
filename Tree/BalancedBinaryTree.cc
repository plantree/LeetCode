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

int max(int x, int y) {
    return x > y ? x : y;
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int height(TreeNode *root) {
    if (!root) {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(TreeNode* root) {
    if (!root) {
        return true;
    }
    if (abs(height(root->left)-height(root->right)) > 1) {
        return false;
    } else {
        return isBalanced(root->left) && isBalanced(root->right);
    }
}

int main() {
    vector<int> nodes ={ 3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = createTree(nodes, 0);
    cout << isBalanced(root) << endl;
}
