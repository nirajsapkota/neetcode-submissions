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
        auto result = std::vector<int>();
        postOrder(root, result);
        return result[k - 1];
    }

    auto postOrder(TreeNode* root, std::vector<int>& result) -> void {
        if (root == nullptr) return;
        postOrder(root->left, result);
        result.push_back(root->val);
        postOrder(root->right, result);
    }
};
