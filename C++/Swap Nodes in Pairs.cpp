#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head)
{
    if(head==NULL||head->next==NULL) return head;
    ListNode *node,*nextnode;
    node=head,nextnode=head->next;
    node->next=nextnode->next;
    nextnode->next=node;
    ListNode *st=nextnode;
    ListNode *prenode=nextnode->next;
    ListNode *cntnode=node->next;
    while(cntnode!=NULL&&cntnode->next!=NULL)
        {
            node=cntnode,nextnode=cntnode->next;
            prenode->next=nextnode;
            node->next=nextnode->next;
            nextnode->next=node;
            cntnode=node->next;
            prenode=node;
        }
    return st;
}