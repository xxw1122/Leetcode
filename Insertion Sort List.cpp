#include<iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head)
{
    if(head==NULL) return NULL;
    ListNode *cntnode=NULL,*prenode=NULL,*nextnode=NULL,*node=NULL;
    cntnode=head->next;
    head->next=NULL;
    while(cntnode)
        {
            node=cntnode->next;
            if(cntnode->val<head->val)
                {
                    cntnode->next=head;
                    head=cntnode;
                }
            else
                {
                    prenode=head;
                    nextnode=head->next;
                    while(nextnode&&(nextnode->val)<cntnode->val)
                        {
                            prenode=pre->next;
                            nextnode=nextnode->next;
                        }
                    prenode->next=cntnode;
                    cntnode->next=nextnode;
                }
            cntnode=node;
        }
    return head;
}

int main()
    {
        return 0;
    }