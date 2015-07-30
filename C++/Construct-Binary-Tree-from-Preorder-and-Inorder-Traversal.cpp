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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int l1, int r1, int l2, int r2) {
        if (l1 > r1) return NULL;
        if (l1 == r1) {
            TreeNode* root = new TreeNode(inorder[l1]);
            return root;
        }
        int pos = 0;
        for (int i = l1; i <= r1; i ++) {
            if (inorder[i] == postorder[r2]) {
                pos = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(postorder[r2]);
        root->left = helper(inorder, postorder, l1, pos - 1, l2, l2 + pos - l1  - 1);
        root->right = helper(inorder, postorder, pos + 1, r1, l2 + pos - l1, r2 - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        return helper(inorder, postorder, 0, len - 1, 0, len - 1);
    }
};