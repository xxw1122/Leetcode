#include<iostream>


using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* findnode(TreeLinkNode *root)
{
    if(root==NULL) return NULL;
    while(root->left==NULL&&root->right==NULL)
        {
            root=root->next;
            if(root==NULL) return NULL;
        }
    if(root->left!=NULL) return root->left;
    return root->right;
}

void connectTree(TreeLinkNode *root,TreeLinkNode *lchild,TreeLinkNode *rchild)
    {
        if(lchild!=NULL&&rchild!=NULL)
            {
                lchild->next=rchild;
                rchild->next=findnode(root->next);
                connectTree(rchild, rchild->left, rchild->right);
                connectTree(lchild, lchild->left, lchild->right);
            }
        else if(lchild!=NULL&&rchild==NULL)
            {
                lchild->next=findnode(root->next);
                connectTree(lchild, lchild->left, lchild->right);
            }
        else if(rchild!=NULL&&lchild==NULL)
            {
                rchild->next=findnode(root->next);
                connectTree(rchild, rchild->left, rchild->right);
            }
        return;
    }


void connect(TreeLinkNode *root)
    {
        if(root==NULL) return;
        connectTree(root, root->left, root->right);
    }