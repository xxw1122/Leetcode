/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        int leftv = helper(root->left), rightv = helper(root->right);
        if (leftv == -1 || rightv == -1 || abs(leftv - rightv) > 1) return -1;
        return max(leftv, rightv) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (helper(root) == -1) return false;
        return true;
    }
};