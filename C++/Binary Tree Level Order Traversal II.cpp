#include<iostream>
#include<vector>
#include<queue>
#include<stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        vector<vector<int> >vec;
        if(root==NULL) return vec;
        queue<TreeNode*>st;
        queue<TreeNode*>st2;
        vector<int> st1;
        stack<vector<int> >st3;
        st.push(root);
        TreeNode *node;
        while(!st.empty())
            {
                while(!st.empty())
                    {
                        node=st.front();
                        st.pop();
                        st2.push(node);
                    }
                st1.clear();
                while(!st2.empty())
                    {
                        node=st2.front();
                        st2.pop();
                        st1.push_back(node->val);
                        if(node->left!=NULL) st.push(node->left);
                        if(node->right!=NULL) st.push(node->right);
                    }
                if(st1.size()>0) st3.push(st1);
            }
        while(!st3.empty())
            {
                vec.push_back(st3.top());
                st3.pop();
            }
        return vec;
    }

