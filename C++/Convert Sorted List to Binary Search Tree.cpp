#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* BST(ListNode *head,ListNode *end){
    if(head==end){
        return NULL;
    }
    TreeNode *root=new TreeNode(sizeof(TreeNode));
    if(head->next==end){
        root->val=head->val;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    ListNode *node1=head,*node2=head;
    while(node2->next!=end){
        node2=node2->next;
        if(node2->next!=end){
            node1=node1->next;
            node2=node2->next;
        }
        else break;
    }
    root->val=node1->val;
    root->left=BST(head,node1);
    root->right=BST(node1->next,end);
    return root;
}

TreeNode *sortedListToBST(ListNode *head){
    if(head==NULL) return NULL;
    ListNode *node1=head,*node2=head;
    while(node2->next!=NULL){
        node2=node2->next;
        if(node2->next!=NULL){
            node1=node1->next;
            node2=node2->next;
        }
        else break;
    }
    TreeNode *root=new TreeNode(sizeof(TreeNode));
    root->val=node1->val;
    root->left=BST(head,node1);
    root->right=BST(node1->next,node2->next);
    return root;
}