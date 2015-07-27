#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head) {
    if(head==NULL) return NULL;
    ListNode *node=head;
    if(node->next==NULL) return head;
    ListNode *cur;
    int cnt;
    while(node->next!=NULL){
        if(node->val==(node->next)->val){
            cnt=node->val;
            while(node->val==cnt){
                node=node->next;
                if(node==NULL) return NULL;
            }
            if(node!=NULL&&node->next==NULL){
                cur=node;
            }
        }
        else{
            cur=node;
            break;
        }
    }
    if(cur->next==NULL) return cur;
    node=cur->next;
    ListNode *node1=cur;
    while(node->next!=NULL){
        if(node->val==(node->next)->val){
            cnt=node->val;
            while(node->val==cnt){
                node=node->next;
                if(node==NULL) break;
            }
            if(node==NULL) break;
        }
        else if(node->val!=(node->next)->val){
            node1->next=node;
            node1=node1->next;
            node=node->next;
        }
    }
    node1->next=node;
    return cur;
}