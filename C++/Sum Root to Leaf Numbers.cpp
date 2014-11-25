#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode *root,int sum,int &res)
    {
        if(root==NULL) return;
        else if(root->left==NULL&&root->right==NULL)
            {
                res=res+sum+root->val;
            }
        else if(root->left==NULL&&root->right!=NULL)
            {
                //res=res+sum;
                dfs(root->right,(sum+root->val)*10,res);
            }
        else if(root->left!=NULL&&root->right==NULL)
            {
                // res=res+sum;
                dfs(root->left,(sum+root->val)*10,res);
            }
        else if(root->left!=NULL&&root->right!=NULL)
            {
                dfs(root->left,(sum+root->val)*10,res);
                dfs(root->right,(sum+root->val)*10,res);
            }
    }

int sumNumbers(TreeNode *root)
    {
        if(root==NULL) return 0;
        int cnt=0;
        dfs(root,0,cnt);
        return cnt;
    }