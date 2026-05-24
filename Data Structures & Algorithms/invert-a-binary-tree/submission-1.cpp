/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        invertTree(root->left);
        invertTree(root->right);
        swapChildren(root);
        return root;
    }

    auto swapChildren(TreeNode* parent) -> void {
        auto left = parent->left;
        parent->left = parent->right;
        parent->right = left;
    }
};
