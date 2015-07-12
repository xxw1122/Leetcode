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
    void helper(vector<vector<int> >& path, vector<int>& cur, TreeNode* root, int sum) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            cur.push_back(root->val);
            path.push_back(cur);
            cur.pop_back();
            return;
        }
        cur.push_back(root->val);
        helper(path, cur, root->left, sum - root->val);
        helper(path, cur, root->right, sum - root->val);
        cur.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > path;
        vector<int> cur;
        helper(path, cur, root, sum);
        return path;
    }
};