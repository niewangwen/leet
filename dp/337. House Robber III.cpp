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
    int rob(TreeNode* root) {
        return helper(root);
    }
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        int res = root->val;
        if (root->left)
            res += helper(root->left->left) + helper(root->left->right);
        if (root->right)
            res += helper(root->right->left) + helper(root->right->right);
        return max(res, helper(root->left) + helper(root->right));
    }
};
