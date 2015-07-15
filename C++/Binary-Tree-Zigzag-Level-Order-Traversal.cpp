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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        queue<TreeNode*> q;
        bool sign = false;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> cur;
            for (int i = 0; i < size; i ++) {
                TreeNode* temp = q.front();
                q.pop();
                cur.push_back(temp->val);
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
            if (sign) reverse(cur.begin(), cur.end());
            sign = !sign;
            res.push_back(cur);
        }
        return res;
    }
};