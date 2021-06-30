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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        // the beginning node is not left node, so we pass false to the function
        helper(root, res, false);
        return res;
    }
    
    void helper(TreeNode* root, int& res, bool isLeft) {
        if (!root)
            return;
        // if root has child, it's not left node
        if (root->left) {
            // if child is left node, perhaps it will be the left node
            helper(root->left, res, true);
            isLeft = false;
        }
        if (root->right) {
            helper(root->right, res, false);
            isLeft = false;
        }
        if (isLeft)
            res += root->val;
    } 
};
