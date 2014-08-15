#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *rotateRight(ListNode *head, int k) {
    if(head==NULL||head->next==NULL) return head;
    ListNode *node=head;
    int len=0;
    ListNode *lastnode;
    while(node!=NULL){
        len++;
        if(node->next==NULL) lastnode=node;
        node=node->next;
    }
    int cnt=k%len;
    if(cnt==0) return head;
    cnt =len-cnt-1;
    node=head;
    ListNode *headnode;
    while(cnt--){
        node=node->next;
    }
    headnode=node->next;
    node->next=NULL;
    lastnode->next=head;
    return headnode;
}