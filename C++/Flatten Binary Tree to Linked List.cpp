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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        if (root->left != NULL) {
        	TreeNode *leftNode = root->left;
        	TreeNode *rightNode = root->right;
        	root->left = NULL;
        	root->right = leftNode;
        	TreeNode* p = leftNode;
        	while (p->right != NULL) {
        		p = p->right;
        	}
        	p->right = rightNode;
        }
        flatten(root->right);
    }
};