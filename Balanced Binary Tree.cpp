#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int Treeheight(TreeNode *root)
    {
        if(root==NULL) return 0;
        else return max(Treeheight(root->left)+1,Treeheight(root->right)+1);
    }

bool isBalanced(TreeNode *root)
    {
        if(root==NULL) return true;
        int len1=Treeheight(root->left),len2=Treeheight(root->right);
        if(max(len1,len2)-min(len1,len2)>1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }