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
	void helper(TreeNode* root, int& pos, int k, int& res) {
		if (root == NULL) return;
		helper(root->left, pos, k, res);
		if (pos == k) {
			res = root->val;
		}
		pos ++;
		helper(root->right, pos, k, res);
	}
    int kthSmallest(TreeNode* root, int k) {
       int res = -1, start = 1; 
       helper(root, start, k, res);
       return res;
    }
};