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
    int getheight(TreeNode* root) {
        if (root == NULL) return 0;
        return getheight(root->left) + 1;
    }
    bool havenode(TreeNode *root, int num, int cur) {
        if (root != NULL && num == 1 && cur == 1) return true;
        else if (root == NULL) return false;
        if (num <= cur / 2) {
            return havenode(root->left, num, cur / 2);
        } else {
            return havenode(root->right, num - cur / 2, cur / 2);
        }
    }
    int countNodes(TreeNode* root) {
        int height = getheight(root);
        if (height <= 1) return height;
        int left = 1, right = 1 << (height - 1), num = 0, cnt = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (havenode(root, mid, cnt)) {
                num = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return num + cnt - 1;
    }
};