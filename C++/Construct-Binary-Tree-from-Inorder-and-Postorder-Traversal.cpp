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
    TreeNode* helper(vector<int>& preorder, int preleft, int preright,
        vector<int>& inorder, int inleft, int inright) {
        if (preleft == preright) {
            TreeNode* root = new TreeNode(preorder[preleft]);
            return root;
        }
        if (preleft > preright) return NULL;
        int pos = -1;
        for (int i = inleft; i <= inright; i ++) {
            if (preorder[preleft] == inorder[i]) {
                pos = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(preorder[preleft]);
        root->left = helper(preorder, preleft + 1, pos - inleft + preleft, inorder, inleft, pos - 1);
        root->right = helper(preorder, pos - inleft + preleft + 1, preright, inorder, pos + 1, inright);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        return helper(preorder, 0, len - 1, inorder, 0, len - 1);
    }
};