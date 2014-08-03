#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root,vector<int>& vec){
    if(root==NULL) return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
    return;
}

bool isValidBST(TreeNode *root) {
    if(root==NULL) return true;
    vector<int> vec;
    inorder(root, vec);
    int len=vec.size();
    if(len<=1) return true;
    for(int i=0;i<len-1;i++){
        if(vec[i]>=vec[i+1]) return false;
    }
    return true;
}