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
    vector<TreeNode*> helper(int left, int right) {
        if (left > right) return vector<TreeNode*>(1, nullptr);
        vector<TreeNode*> vec;
        for (int k = left; k <= right; k ++) {
            vector<TreeNode*> lt = helper(left, k - 1);
            vector<TreeNode*> rt = helper(k + 1, right);
            for (int i = 0; i < lt.size(); i ++) {
                for (int j = 0; j < rt.size(); j ++) {
                    TreeNode* root = new TreeNode(k);
                    root->left = lt[i];
                    root->right = rt[j];
                    vec.push_back(root);
                }
            }
        }
        return vec;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};
