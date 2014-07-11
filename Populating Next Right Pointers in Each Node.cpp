#include<iostream>


using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connectTree(TreeLinkNode *root,TreeLinkNode *lchild,TreeLinkNode *rchild)
    {
        if(lchild==NULL||rchild==NULL) return;
        lchild->next=rchild;
        if(root->next!=NULL) rchild->next=(root->next)->left;
        else rchild->next=NULL;
        connectTree(lchild, lchild->left, lchild->right);
        connectTree(rchild, rchild->left, rchild->right);
    }


void connect(TreeLinkNode *root)
    {
        if(root==NULL) return;
        connectTree(root, root->left, root->right);
    }