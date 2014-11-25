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

void dfs(vector<int> &vec,TreeNode *root)
    {
        if(root->left!=NULL) dfs(vec,root->left);
        vec.push_back(root->val);
        if(root->right!=NULL) dfs(vec,root->right);
    }

vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        stack<int> num;
        stack<TreeNode*> st;
        if(root!=NULL) st.push(root);
        TreeNode *node;
        while(!st.empty())
            {
                node=st.top();
                st.pop();
                if(node->left!=NULL) st.push(node->left);
                if(node->right!=NULL) st.push(node->right);
                num.push(node->val);
            }
        while(!num.empty())
            {
                vec.push_back(num.top());
                num.pop();
            }
        return vec;
    }

int main()
    {
        return 0;
    }