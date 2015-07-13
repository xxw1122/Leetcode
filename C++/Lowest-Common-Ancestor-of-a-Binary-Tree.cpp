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
	bool cover(TreeNode* root, TreeNode* node) {
		if (root == NULL) return false;
		if (root == node) return true;
		if (cover(root->left, node) || cover(root->right, node)) return true;
		return false;
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (1) {
        	if (root == p || root == q) return root;
        	bool Lcoverp = cover(root->left, p), Lcoverq = cover(root->left, q);
        	if (Lcoverp && Lcoverq) root = root->left;
        	else if (!Lcoverq && !Lcoverp) root = root->right;
        	else return root;
        }
    }
};