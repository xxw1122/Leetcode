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
	bool helper(TreeNode* root, int &res) {
		if (root == NULL) return true;
		if (root->left == NULL && root->right == NULL) {
			res += 1;
			return true;
		}
		if (root->left == NULL) {
			if (helper(root->right, res) && root->val == root->right->val) {
				res += 1;
				return true;
			}
		} else if (root->right == NULL) {
			if (helper(root->left, res) && root->val == root->left->val) {
				res += 1;
				return true;
			}
		} else {
			bool cur1 = helper(root->left, res);
			bool cur2 = helper(root->right, res);
			if (cur1 && cur2 && root->val == root->left->val && root->val == root->right->val) {
				res += 1;
				return true;
			}
		}
		return false;
	}
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};