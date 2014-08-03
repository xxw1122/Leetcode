#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *makeTree(vector<int>&inorder,int pos1,int pos2,vector<int>&postorder,int pos3,int pos4){
    if(pos1>pos2) return NULL;
    TreeNode *root=new TreeNode(sizeof(TreeNode));
    if(pos1==pos2){
        root->val=inorder[pos1];
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    int cnt;
    for(int i=pos1;i<=pos2;i++){
        if(inorder[i]==postorder[pos4]){
            cnt=i;
            break;
        }
    }
    root->val=inorder[cnt];
    root->left=makeTree(inorder,pos1,cnt-1,postorder,pos3,pos3+cnt-pos1);
    root->right=makeTree(inorder,cnt+1,pos2,postorder,pos3+cnt-pos1+1,pos4-1);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int len1=inorder.size(),len2=postorder.size();
    if(len1==0) return NULL;
    int pos;
    for(int i=0;i<len1;i++){
        if(inorder[i]==postorder[len1-1]){
            pos=i;
            break;
        }
    }
    TreeNode *root=new TreeNode(sizeof(TreeNode));
    root->val=inorder[pos];
    root->left=makeTree(inorder,0,pos-1,postorder,0,pos-1);
    root->right=makeTree(inorder, pos+1, len1-1, postorder, pos, len1-2);
    return root;
}

