#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int maxDepth(TreeNode *root)
    {
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return 1;
        int cnt=max(maxDepth(root->left),maxDepth(root->right))+1;
        return cnt;
    }