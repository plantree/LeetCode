#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// inorder and postorder
/*
TreeNode* buildTree(vector<int>&inorder, int ileft, int iright, 
                    vector<int>& postorder, int pleft, int pright) {
    if (ileft > iright || pleft > pright) {
        return nullptr;
    }
    int rootVal = postorder[pright];
    TreeNode *root = new TreeNode(rootVal);
    int i = ileft;
    while (inorder[i] != rootVal) {
        i++;
    }
    TreeNode *leftNode = buildTree(inorder, ileft, i-1,
                               postorder, pleft, pleft+i-ileft-1);
    TreeNode *rightNode = buildTree(inorder, i+1, iright,
                                postorder, pleft+i-ileft, pright-1);
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTree(inorder, 0, inorder.size() - 1, 
                    postorder, 0, postorder.size() - 1);
}
*/

// preorder and inorder
/*
TreeNode* buildTree(vector<int>& preorder, int pleft, int pright,
                   vector<int>& inorder, int ileft, int iright) {
    if (pleft > pright || ileft > iright) {
        return nullptr;
    }                  
    int rootVal = preorder[pleft];
    TreeNode *root = new TreeNode(rootVal);
    int i = ileft;
    while (inorder[i] != rootVal) {
        i++;
    } 
    TreeNode *leftNode = buildTree(preorder, pleft+1, pleft+i-ileft,
                                   inorder, ileft, ileft+i-1);
    TreeNode *rightNode = buildTree(preorder, pleft+i-ileft+1, pright,
                                    inorder, i+1, iright);
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(preorder, 0, preorder.size() - 1,
                    inorder, 0, inorder.size() - 1);
}
*/

// preorder and postorder
TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight,
                    vector<int>& postorder, int postLeft, int postRight) {
    if (preLeft > preRight || postLeft > postRight) {
        return nullptr;
    }                  
    int rootVal = preorder[preLeft];
    TreeNode *root = new TreeNode(rootVal);
    int leftVal = preorder[preLeft+1],
        rightVal = postorder[postRight-1];

    // 某一子树不存在（这里都归为左子树）
    if (leftVal == rightVal) {
        TreeNode *leftNode = buildTree(preorder, preLeft+1, preRight,
                                       postorder, postLeft, postRight-1);
        root->left = leftNode;
    } else {
        int i = preLeft,
            j = postRight;
        while (preorder[i] != rightVal) {
            i++;
        }
        while (postorder[j] != leftVal) {
            j--;
        }
        TreeNode *leftNode = buildTree(preorder, preLeft+1, i-1,
                                       postorder, postLeft, j);
        TreeNode *rightNode = buildTree(preorder, i, preRight,
                                        postorder, j+1, postRight-1);
        root->left = leftNode;
        root->right = rightNode;
    }
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder) {
    return buildTree(preorder, 0, preorder.size() - 1,
                    postorder, 0, postorder.size() - 1);
}

void preOrderTraversal(TreeNode *root) {
    if (root) {
        cout << root->val << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {

    // inorder and postorder
    /*
    vector<int> inorder = {9, 3, 15, 20, 7},
                postorder = {9, 15, 7, 20, 3};
    TreeNode *root = buildTree(inorder, postorder);
    */

    // preorder and inorder
    /*
    vector<int> preorder = {3, 9, 20, 15, 7},
                inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(preorder, inorder);
    */

    // preorder and postorder
    vector<int> preorder = {3, 9, 20, 15, 7},
                postorder = {9, 15, 7, 20, 3};
    TreeNode *root = buildTree(preorder, postorder);

    preOrderTraversal(root);
    cout << endl;
}