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
// 删除节点后调整子树使其重新符合BST设定
// 方法：将左子树最大节点/右子树最小节点 调整为根节点，删除原来根节点
// 实现：将新的根节点值赋给根节点，然后在对应子树中删除对应值的节点
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left || !root->right)
                root = root->left ? root->left : root->right;
            else {
                TreeNode* tmp = root->left;
                while (tmp->right)
                    tmp = tmp->right;
                root->val = tmp->val;
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }

};
