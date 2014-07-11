#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };


ListNode *mergeTwoLists(ListNode *l1,ListNode *l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode *node;
    if(l1->val<l2->val)
    {
        node=l1->next;
        l1->next=mergeTwoLists(node, l2);
        return l1;
    }
    else
    {
        node=l2->next;
        l2->next=mergeTwoLists(l1, node);
        return l2;
    }
    return NULL;
}
