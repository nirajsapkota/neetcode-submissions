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
    vector<vector<int>> levelOrder(TreeNode* root) {
        auto levelOrder = std::vector<std::vector<int>>();
        if (root == nullptr) return levelOrder;

        auto q = std::queue<TreeNode*>();
        q.push(root);
        
        while (!q.empty()) {
            auto nodesInLevel = std::vector<TreeNode*>();
            for (; !q.empty(); q.pop()) {
                auto front = q.front();
                nodesInLevel.push_back(front);
            }

            auto level = std::vector<int>();
            for (auto const& node : nodesInLevel) {
                level.push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            levelOrder.push_back(level);
        }

        return levelOrder;
    }
};
