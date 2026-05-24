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
    bool isValidBST(TreeNode* root) {
        return valid(root, INT_MIN, INT_MAX);
    }

    auto valid(TreeNode* node, int left, int right) -> bool {
        if (node == nullptr) return true;
        auto leftValid = valid(node->left, left, node->val);
        auto rightValid = valid(node->right, node->val, right);
        auto thisValid = node->val > left && node->val < right;
        return thisValid && leftValid && rightValid;
    }
};
