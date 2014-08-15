#include<iostream>

using namespaces std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *mergelist(ListNode *head1,ListNode *head2)
{
    ListNode *temp;
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    if(head1->val<head2->val)
        {
            temp=head1;
            head1=head1->next;
        }
    else
        {
            temp=head2;
            head2=head2->next;
        }
    temp->next=mergelist(head1, head2);
    return temp;
}

ListNode *sortList(ListNode *head)
{
    if(head==NULL) return NULL;
    ListNode *r_head=head;
    ListNode *head1=head;
    ListNode *head2=head;
    //if(head->next) return head;
    while(head2->next!=NULL&&head2->next->next!=NULL)
        {
            head1=head1->next;
            head2=head2->next->next;
        }
    if(head1->next==NULL) return r_head;
    head2=head1->next;
    head1->next=NULL;
    head1=head;
    r_head=mergelist(sortList(head1),sortList(head2));
    return r_head;
}

int main()
    {
        return 0;
    }