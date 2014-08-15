#include<iostream>
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findpath(vector<vector<int> >&vec,vector<int> &st,TreeNode *root,int sum,int cur)
    {
        if(root->left==NULL&&root->right==NULL&&cur+root->val==sum)
            {
                st.push_back(root->val);
                vec.push_back(st);
                st.pop_back();
                return;
            }
        if(root->left==NULL&&root->right==NULL&&cur+root->val==sum)
            {
                vec.pop_back();
                return;
            }
        if(root->left!=NULL)
            {
                st.push_back(root->val);
                findpath(vec, st, root->left, sum, cur+root->val);
                st.pop_back();
            }
        if(root->right!=NULL)
            {
                st.push_back(root->val);
                findpath(vec, st, root->right, sum, cur+root->val);
                st.pop_back();
            }
        return ;
    }

vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        vector<vector<int> > vec;
        if(root==NULL) return vec;
        vector<int> st;
        findpath(vec, st, root, sum, 0);
        return vec;
    }