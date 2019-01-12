#include <iostream>
#include <vector>
#include <string>

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

void helper(TreeNode *root, string lastPath, vector<string>& res) {
    if (!root) {
        return;
    }
    if (lastPath == "") {
        lastPath = to_string(root->val);
    } else {
        lastPath += "->" + to_string(root->val);
    }

    if (!root->left && !root->right) {
        res.push_back(lastPath);
    }
    if (root->left) {
        helper(root->left, lastPath, res);
    } 
    if (root->right) {
        helper(root->right, lastPath, res);
    }
}

vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> res;
    helper(root, "", res);
    return res;
}

int main() {
    vector<int> nodes = {1, 2, 3, -1, 5};
    TreeNode *root = createTree(nodes, 0);
    auto paths = binaryTreePaths(root);
    for (auto path : paths) {
        cout << path << " ";
    }
    cout << endl;
}