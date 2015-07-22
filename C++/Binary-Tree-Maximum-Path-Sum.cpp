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
private:
    int maxP;
public:
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        int leftv = helper(root->left);
        int rightv = helper(root->right);
        int temp = max(0, max(leftv, rightv)) + root->val;
        maxP = max(maxP, max(temp, root->val + leftv + rightv));
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        maxP = INT_MIN;
        helper(root);
        return maxP;
    }
};