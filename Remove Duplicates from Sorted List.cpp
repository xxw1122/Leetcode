#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *deleteDuplicates(ListNode *head)
{
    if(head==NULL||head->next==NULL) return head;
    ListNode *node1=head->next,*node2=head;
    while(node1!=NULL)
        {
            if(node1->val==node2->val)
                {
                    node2->next=node1->next;
                    node1=node1->next;
                }
            else
                {
                    node2=node1;
                    node1=node1->next;
                }
        }
    return head;
}