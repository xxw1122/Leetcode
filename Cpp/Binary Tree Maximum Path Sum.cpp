#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root,int& maxnum){
    int cnt=root->val;
    if(root->left!=NULL&&root->right!=NULL){
        dfs(root->left,maxnum);
        dfs(root->right,maxnum);
        maxnum=max(maxnum,max(cnt,max(cnt+root->left->val+root->right->right,max(cnt+root->left->val,cnt+root->right->val))));
        root->val=max(cnt,max(cnt+root->left->val,cnt+root->right->val));
    }
    else if(root->left==NULL&&root->right!=NULL){
        dfs(root->right,maxnum);
        root->val=max(cnt,cnt+root->right->val);
    }
    else if(root->left!=NULL&&root->right==NULL){
        dfs(root->left,maxnum);
        root->val=max(cnt,cnt+root->left->val);
    }
    maxnum=max(maxnum,root->val);
    return;
}

int maxPathSum(TreeNode *root) {
    if(root==NULL) return 0;
    int maxnum=root->val;
    dfs(root,maxnum);
    return maxnum;
}
