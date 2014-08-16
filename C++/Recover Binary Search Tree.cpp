#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root,vector<int>&vec){
    if(root==NULL) return;
    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
    return;
}

void swapvalue(TreeNode *root,int pos1,int val1,int pos2,int val2,int &pos){
    if(root->left!=NULL) swapvalue(root->left, pos1, val1, pos2, val2, pos);
    if(pos==pos1) root->val=val2;
    if(pos==pos2) root->val=val1;
    pos++;
    if(root->right!=NULL) swapvalue(root->right,pos1,val1,pos2,val2,pos);
}

void recoverTree(TreeNode *root) {
    vector<int>vec;
    inorder(root, vec);
    int len=vec.size();
    int pos1,pos2;
    int val1,val2;
    for(int i=0;i<len;i++){
        if(i+1<len&&vec[i+1]<vec[i]){
            pos1=i;
            val1=vec[pos1];
            break;
        }
    }
    for(int i=len-1;i>=0;i--){
        if(i-1>=0&&vec[i]<vec[i-1]){
            pos2=i;
            val2=vec[pos2];
            break;
        }
    }
    int cnt=0;
    swapvalue(root, pos1, val1, pos2, val2, cnt);
}

