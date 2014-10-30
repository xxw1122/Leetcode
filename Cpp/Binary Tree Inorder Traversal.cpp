#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        stack<TreeNode*> st;
        while(root||!st.empty())
            {
                if(root!=NULL)
                    {
                        st.push(root);
                        root=root->left;
                    }
                else
                    {
                        root=st.top();
                        vec.push_back(root->val);
                        st.pop();
                        root=root->right;
                    }
            }
        return vec;
    }