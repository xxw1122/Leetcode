#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(vector<int> &vec,TreeNode *root)
    {
        vec.push_back(root->val);
        if(root->left!=NULL) dfs(vec,root->left);
        if(root->right!=NULL) dfs(vec,root->right);
    }


vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        stack<TreeNode*> st;
        TreeNode *node;
        while(root||!st.empty())
            {
                while(root)
                    {
                        st.push(root);
                        vec.push_back(root->val);
                        root=root->left;
                    }
                root=st.top();
                st.pop();
                root=root->right;
            }
        return vec;
    }

