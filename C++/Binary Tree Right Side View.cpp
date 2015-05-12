#include <vector>
#include <queue>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void bfs(TreeNode *root, vector<int> &res) {
        if (root == NULL) return;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        TreeNode *cnt;
        while (!q1.empty() || !q2.empty()) {
            while (!q1.empty()) {
                cnt = q1.front();
                q1.pop();
                if (cnt->left) q2.push(cnt->left);
                if (cnt->right) q2.push(cnt->right);
                if (q1.empty()) res.push_back(cnt->val);
            }
            while (!q2.empty()) {
                cnt = q2.front();
                q2.pop();
                if (cnt->left) q1.push(cnt->left);
                if (cnt->right) q1.push(cnt->right);
                if (q2.empty()) res.push_back(cnt->val);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        bfs(root, res);
        return res;
    }
};