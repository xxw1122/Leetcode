#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
    if(head==NULL) return head;
    ListNode *node=head;
    ListNode *prenode1=NULL,*prenode2=NULL;
    ListNode *head1=NULL,*head2=NULL;
    while(node!=NULL){
        if(node->val<x){
            if(prenode1==NULL){
                prenode1=node;
                head1=node;
            }
            else{
                prenode1->next=node;
                prenode1=prenode1->next;
            }
        }
        else{
            if(prenode2==NULL){
                prenode2=node;
                head2=node;
            }
            else{
                prenode2->next=node;
                prenode2=prenode2->next;
            }
        }
        node=node->next;
    }
    if(prenode2!=NULL) prenode2->next=NULL;
    if(prenode1==NULL){
        return head2;
    }
    prenode1->next=head2;
    return head1;
}
