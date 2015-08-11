/**
 * 
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode *curr = root;
        TreeNode *prev = NULL;
        TreeNode *next = NULL;
        TreeNode *temp = NULL;

        while (curr != NULL) {
            next = curr->left;
            curr->left = temp;
            temp = curr->right;
            curr->right = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};