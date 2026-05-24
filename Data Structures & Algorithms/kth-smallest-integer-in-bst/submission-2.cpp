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
    int kthSmallest(TreeNode* root, int k) {
        auto treeValues = std::vector<int>();
        inOrder(root, treeValues);
        return treeValues[k - 1];
    }

    auto inOrder(TreeNode* root, std::vector<int>& result) -> void {
        if (root == nullptr) return;
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
};
