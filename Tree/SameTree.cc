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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if ((p && !q) || (!p && q)) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    } else {
        return isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
}

int main() {
    vector<int> nodes1 = {1, 2, 3},
                nodes2 = {1, 2, 3};
    TreeNode *p = createTree(nodes1, 0),
             *q = createTree(nodes2, 0);
    cout << isSameTree(p, q) << endl;

    nodes1 = {1, 2};
    nodes2 = {1, -1, 2};
    p = createTree(nodes1, 0);
    q = createTree(nodes2, 0);
    cout << isSameTree(p, q) << endl;

}