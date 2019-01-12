#include <iostream>
#include <vector>
#include <stack>

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


vector<int> preOrderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    stack<TreeNode*> temp;
    temp.push(root);
    while (!temp.empty()) {
        TreeNode *node = temp.top();
        temp.pop();
        res.push_back(node->val);
        if (node->right) {
            temp.push(node->right);            
        }
        if (node->left) {
            temp.push(node->left);
        }
    }
    return res;
}

vector<int> inOrderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    stack<TreeNode*> temp;
    TreeNode *p = root;
    while (p || !temp.empty()) {
        while (p) {
            temp.push(p);
            p = p->left;
        }
        p = temp.top();
        temp.pop();
        res.push_back(p->val);
        p = p->right;
    }
    return res;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    stack<TreeNode*> temp;
    temp.push(root);
    TreeNode *head = root;
    while (!temp.empty()) {
        TreeNode *node = temp.top();
        if ((!node->left && !node->right) ||
            (node->left == head || node->right == head)) {
                res.push_back(node->val);
                temp.pop();
                head = node;
        } else {
            if (node->right) {
                temp.push(node->right);
            }
            if (node->left) {
                temp.push(node->left);
            }
        }
    }
    return res;
}

int main() {
    vector<int> nodes = {1, 2, 3, 4, 5};
    TreeNode *root = createTree(nodes, 0);
    //auto orders = preOrderTraversal(root);
    //auto orders = inOrderTraversal(root);
    auto orders = postorderTraversal(root);
    for (auto item : orders) {
        cout << item << " ";
    }
    cout << endl;
}