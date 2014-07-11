#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *BuildTree(vector<int> &A,int l,int r)
    {
        if(l>r) return NULL;
        int mid=(l+r)/2;
        TreeNode *node = new TreeNode(A[mid]);
        node->left=BuildTree(A, l, mid-1);
        node->right=BuildTree(A, mid+1, r);
        return node;
    }

TreeNode *sortedArrayToBST(vector<int> &num)
    {
        if(num.size()==0) return NULL;
        int len=num.size();
        return BuildTree(num,0,len-1);
    }