#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL||q==NULL) return false;
        if(p->val!=q->val) return false;
        else return (isSameTree(p->left, q->left)&&isSameTree(p->right, q->right));
    }