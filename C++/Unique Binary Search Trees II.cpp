#include <iostream>
#include <vector>
#include <stack>
#include <iterator>

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
    root->left=makeTree(inorder,pos1,cnt-1,postorder,pos3,pos3+cnt-pos1-1);
    root->right=makeTree(inorder,cnt+1,pos2,postorder,pos3+cnt-pos1,pos4-1);
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

void gernerate(vector<vector<int> >&st,vector<int>&st1,stack<int>&st2,int pos,int len){
    if(pos==len+1){
        if(st2.empty()){
            st.push_back(st1);
        }
        else{
            int num=st2.size();
            while(!st2.empty()){
                st1.push_back(st2.top());
                st2.pop();
            }
            st.push_back(st1);
            while(num--){
                st2.push(st1.back());
                st1.pop_back();
            }
        }
        return;
    }
    st2.push(pos);
    gernerate(st, st1, st2, pos+1, len);
    st2.pop();
    if(!st2.empty()){
        int cnt=st2.top();
        st2.pop();
        st1.push_back(cnt);
        gernerate(st, st1, st2, pos, len);
        st1.pop_back();
        st2.push(cnt);
    }
    return;
}

vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode*> vec;
    if(n==0){
        TreeNode *root=NULL;
        vec.push_back(root);
        return vec;
    }
    vector<int>inorder;
    for(int i=1;i<=n;i++)
        inorder.push_back(i);
    vector<vector<int> >st;
    vector<int> st1;
    stack<int> st2;
    gernerate(st,st1,st2,1,n);
    for(int i=0;i<st.size();i++){
        TreeNode *root=buildTree(inorder, st[i]);
        vec.push_back(root);
    }
    return vec;
}

int main(){
    int num;
    while(cin>>num){
        vector<vector<int> >st;
        vector<int> st1;
        stack<int> st2;
        gernerate(st,st1,st2,1,num);
        sort(st.begin(),st.end());
        vector<vector<int> >::iterator it;
        it=unique(st.begin(),st.end());
        vector<vector<int> >st3(st.begin(),it);
        for(int i=0;i<st.size();i++){
            for(int j=0;j<st[i].size();j++){
                cout<<st[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}