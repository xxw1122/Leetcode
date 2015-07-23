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
    int prev;
    bool first;
public:
    bool helper(TreeNode* root) {
        if (root == NULL) return true;
        if (!helper(root->left)) return false;
        if (first == false && root->val <= prev) return false;
        first = false, prev = root->val;
        if (!helper(root->right)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        first = true;
        prev = INT_MIN;
        return helper(root);
    }
};