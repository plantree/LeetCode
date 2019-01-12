#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right ){
    if (left > right) {
        return nullptr;
    }
    if (left == right) {
        return new TreeNode(nums[left]);
    }
    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, left, mid-1);
    root->right = sortedArrayToBST(nums, mid+1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size()-1);
}