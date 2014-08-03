#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *makeTree(vector<int>&preorder,int pos1,int pos2,vector<int>&inorder,int pos3,int pos4){
    if(pos1>pos2) return NULL;
    TreeNode *root=new TreeNode(sizeof(TreeNode));
    if(pos1==pos2){
        root->val=preorder[pos1];
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    int cnt;
    for(int i=pos3;i<=pos4;i++){
        if(inorder[i]==preorder[pos1]){
            cnt=i;
            break;
        }
    }
    root->val=inorder[cnt];
    root->left=makeTree(preorder,pos1+1,pos1+cnt-pos3,inorder,pos3,cnt-1);
    root->right=makeTree(preorder,pos1+cnt-pos3+1,pos2,inorder,cnt+1,pos4);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int len1=inorder.size(),len2=postorder.size();
    if(len1==0) return NULL;
    int pos;
    for(int i=0;i<len1;i++){
        if(inorder[i]==preorder[0]){
            pos=i;
            break;
        }
    }
    TreeNode *root=new TreeNode(sizeof(TreeNode));
    root->val=inorder[pos];
    root->left=makeTree(preorder,1,pos,inorder,0,pos-1);
    root->right=makeTree(preorder, pos+1, len1-1, inorder, pos+1, len1-1);
    return root;
}

