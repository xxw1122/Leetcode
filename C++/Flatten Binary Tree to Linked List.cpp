#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(stack<TreeNode *>st,TreeNode *root){
    st.push(root);
    if(root->left!=NULL) traverse(st, root->left);
    if(root->right!=NULL) traverse(st, root->right);
}

void flatten(TreeNode *root) {
    if(root==NULL) return;
    stack<TreeNode *>st;
    traverse(st, root);
    TreeNode *node=NULL;
    while(!st.empty()){
        TreeNode *node1=st.top();
        node1->right=node;
        node1->left=NULL;
        node=node1;
        st.pop();
    }
}