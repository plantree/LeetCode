#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> generateTrees(int start, int end) {
    vector<TreeNode*> res;
    if (start > end) {
        res.push_back(nullptr);
        return res;
    }

    for (int i = start; i <= end; ++i) {
        auto l = generateTrees(start, i - 1);
        auto r = generateTrees(i + 1, end);

        for (int j = 0; j < l.size(); ++j) {
            for (int k = 0; k < r.size(); ++k) {
                TreeNode *node = new TreeNode(i);
                node->left = l[j];
                node->right = r[k];
                res.push_back(node);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
        return vector<TreeNode*>();
    }
    return generateTrees(1, n);
}

void levelOrder(TreeNode *root) {
    queue<TreeNode*> q;
    if (!root) {
        return;
    }
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
        cout << node->val << " ";
    }
}

int main() {
    int n = 3;
    auto res = generateTrees(n);
    for (auto item : res) {
        levelOrder(item);
        cout << endl;
    }
}