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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {        
        if (root == nullptr && subRoot != nullptr) return false;
        auto isSame = isSameTree(root, subRoot);
        auto leftIsSame = isSubtree(root->left, subRoot);
        auto rightIsSame = isSubtree(root->right, subRoot);
        return isSame || leftIsSame || rightIsSame;
    }

    auto isSameTree(TreeNode* p, TreeNode* q) -> bool {
        if (p == nullptr && q == nullptr) return true;
        if (p != nullptr && q == nullptr) return false;
        if (p == nullptr && q != nullptr) return false;
        return p->val == q->val &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right);
    }
};
