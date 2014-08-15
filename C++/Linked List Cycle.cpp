#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    ListNode *node1,*node2;
    node1=head,node2=head;
    node1=node1->next,node2=(node2->next)->next;
    if(node1==NULL||node2==NULL) return false;
    while(node1!=node2)
        {
            node1=node1->next;
            node2=node2->next;
            if(node2==NULL) return false;
            node2=node2->next;
            if(node2==NULL) return false;
        }
    return true;
    }

int main()
    {
        return 0;
    }