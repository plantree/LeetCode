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

void helper(TreeNode* node, int sum, vector<int>& out, vector<vector<int>>& res) {
    if (!node) {
        return;
    }
    out.push_back(node->val);
    if (node->val == sum && !node->left && !node->right) {
        res.push_back(out);
    }
    // 在中间结果的基础上递归
    helper(node->left, sum-node->val, out, res);
    helper(node->right, sum-node->val, out, res);
    // 及时清理无关结果
    out.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> out;
    helper(root, sum, out, res);
    return res;
}

int main() {
    vector<int> nodes = {5, 4, 8, 11, -1, 13, 4};
    TreeNode *root = createTree(nodes, 0);
    auto res = pathSum(root, 17);
    for (auto line : res) {
        for (auto item : line) {
            cout << item << " ";
        }
        cout << endl;
    }
}

