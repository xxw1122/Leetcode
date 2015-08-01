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
    void helper(TreeNode* root, vector<int> &res) {
        if (root == NULL) return;
        res.push_back(root->val);
        helper(root->left, res);        
        helper(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != NULL || !stk.empty()) {
            while (root != NULL) {
                res.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            TreeNode *cur = stk.top();
            stk.pop();
            root = cur->right;
        }
        return res;
    }
};