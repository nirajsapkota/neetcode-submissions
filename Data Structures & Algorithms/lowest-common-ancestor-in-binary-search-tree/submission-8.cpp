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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        if (left != nullptr) return left;

        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (right != nullptr) return right;

        auto descendants = getDescendants(root);
        if (descendants.contains(p->val) && descendants.contains(q->val)) return root;

        return nullptr;
    }

    auto getDescendants(TreeNode* root) -> std::unordered_set<int> {
        auto descendants = std::unordered_set<int>();

        auto queue = std::queue<TreeNode*>();
        queue.push(root);

        for (; !queue.empty(); queue.pop()) {
            auto node = queue.front();
            if (node->left != nullptr) queue.push(node->left);
            if (node->right != nullptr) queue.push(node->right);
            descendants.insert(node->val);
        }

        return descendants;
    }
};
