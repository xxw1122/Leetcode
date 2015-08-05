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
    TreeNode* firstElement;
    TreeNode* secondElement;
    TreeNode* prevElement;
    void recoverTree(TreeNode* root) {
        firstElement = NULL;
        secondElement = NULL;
        prevElement = new TreeNode(INT_MIN);
        traverse(root);
        int temp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = temp;
    }
    void traverse(TreeNode* root) {
        if (root == NULL) return;
        traverse(root->left);
        if (firstElement == NULL && prevElement->val >= root->val) {
            firstElement = prevElement;
        }
        if (firstElement != NULL && prevElement->val >= root->val) {
            secondElement = root;
        }
        prevElement = root;
        traverse(root->right);
    }
};