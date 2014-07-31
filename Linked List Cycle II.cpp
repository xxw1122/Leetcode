#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if(head==NULL) return NULL;
    ListNode *node1,*node2;
    node1=head,node2=head;
    node1=node1->next;
    if(node1==NULL) return NULL;
    node2=(node2->next)->next;
    if(node2==NULL) return NULL;
    int cnt=1;
    while(node1!=node2){
        node1=node1->next;
        node2=node2->next;
        if(node2==NULL) return NULL;
        node2=node2->next;
        if(node2==NULL) return NULL;
        cnt++;
    }
    ListNode *node=head;
    for(int i=0;i<cnt;i++)
        node=node->next;
    ListNode *node3=head;
    while(node!=node3){
        node=node->next;
        node3=node3->next;
    }
    return node;
}

int main()
    {
        return 0;
    }