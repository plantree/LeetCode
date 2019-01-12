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

void helper(TreeNode* root, int lastDigit, int& sum) {
    if (!root) {
        return;
    }
    lastDigit = 10 * lastDigit + root->val;
    if (!root->left && !root->right) {
        sum += lastDigit;
        return;
    }
    if (root->left) {
        helper(root->left, lastDigit, sum);
    }
    if (root->right) {
        helper(root->right, lastDigit, sum);
    }

}
int sumNumbers(TreeNode* root) {
    int sum = 0;
    helper(root, 0, sum);
    return sum;
}

int main() {
   vector<int> nodes = {1, 2, 3};
   TreeNode *root = createTree(nodes, 0);
   cout << sumNumbers(root) << endl;
}

