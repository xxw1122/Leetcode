#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool symmetric(TreeNode *root1,TreeNode *root2)
    {
        if(root1==NULL&&root2==NULL) return true;
        else if(root1!=NULL&&root2!=NULL)
            {
                if(root1->val!=root2->val) return false;
                return symmetric(root1->left, root2->right)&&symmetric(root1->right, root2->left);
            }
        else return false;
    }

bool isSymmetric(TreeNode *root)
    {
        if(root==NULL) return true;
        return symmetric(root->left, root->right);
    }