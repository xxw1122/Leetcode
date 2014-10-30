#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> >vec;
    if(root==NULL) return vec;
    queue<TreeNode*> st1,st2;
    st1.push(root);
    vector<int> vec1;
    while(!st1.empty()||!st2.empty()){
        while(!st1.empty()){
            TreeNode *node=st1.front();
            vec1.push_back(node->val);
            if(node->left!=NULL) st2.push(node->left);
            if(node->right!=NULL) st2.push(node->right);
            st1.pop();
        }
        if(vec1.size()>0) vec.push_back(vec1);
        vec1.clear();
        while(!st2.empty()){
            TreeNode *node=st2.front();
            vec1.push_back(node->val);
            if(node->left!=NULL) st1.push(node->left);
            if(node->right!=NULL) st1.push(node->right);
            st2.pop();
        }
        reverse(vec1.begin(),vec1.end());
        if(vec1.size()>0) vec.push_back(vec1);
        vec1.clear();
    }
    return vec;
}