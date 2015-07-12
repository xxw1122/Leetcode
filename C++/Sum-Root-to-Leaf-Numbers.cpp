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
    void helper(TreeNode *root, int &res, int cur) {
        if (root == NULL) return;
        cur = cur * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            res += cur;
            return;
        }
        helper(root->left, res, cur);
        helper(root->right, res, cur);
    }
    int sumNumbers(TreeNode* root) {
        int res = 0;
        helper(root, res, 0);
        return res;
    }
};