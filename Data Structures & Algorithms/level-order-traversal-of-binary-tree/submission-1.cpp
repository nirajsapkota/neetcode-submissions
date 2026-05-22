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
        auto result = std::vector<std::vector<int>>();
        if (root == nullptr) return result;

        auto queue = std::queue<TreeNode*>();
        queue.push(root);
        
        while (!queue.empty()) {
            auto level = std::vector<int>();
            auto levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                auto front = queue.front();
                queue.pop();

                level.push_back(front->val);
                if (front->left != nullptr) queue.push(front->left);
                if (front->right != nullptr) queue.push(front->right);
            }
            result.push_back(level);
        }

        return result;
    }
};
