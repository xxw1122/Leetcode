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
	void findKth(TreeNode *root, int k, int &cur, int &res) {
		if (root == NULL) return; 
		findKth(root->left, k, cur, res);
		if (k == cur) {
			res = root->val;
			//return;
		}
		cur ++;
		findKth(root->right, k, cur, res);
	}
    int kthSmallest(TreeNode* root, int k) {
        int res = -1, cur = 1;
        findKth(root, k, cur, res);
        return res;
    }
};