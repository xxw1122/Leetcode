#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode *root)
    {
        if(root==NULL) return NULL;
        if(root->left!=NULL&&root->right!=NULL) return min(depth(root->left)+1,depth(root->right)+1);
        else if(root->left==NULL&&root->right!=NULL) return depth(root->right)+1;
        else if(root->left!=NULL&&root->right==NULL) return depth(root->left)+1;
        else return 1;
    }

int minDepth(TreeNode *root)
    {
        int d=depth(root);
        return d;
    }