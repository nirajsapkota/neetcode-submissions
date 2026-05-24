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
        if (root == nullptr) return false;
        if (subRoot == nullptr) return true;
        auto leftIsSubtree = isSubtree(root->left, subRoot);
        auto rightIsSubtree = isSubtree(root->right, subRoot);
        auto thisIsSubtree = isSameTree(root, subRoot);
        return thisIsSubtree || leftIsSubtree || rightIsSubtree;
    }

    auto isSameTree(TreeNode* p, TreeNode* q) -> bool {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr && q != nullptr) return false;
        if (p != nullptr && q == nullptr) return false;
        auto leftIsSame = isSameTree(p->left, q->left);
        auto rightIsSame = isSameTree(p->right, q->right);
        return p->val == q->val && leftIsSame && rightIsSame;
    }
};
