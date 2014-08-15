#include <iotream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m==n) return head;
    ListNode *prenode1=head,*prenode2=head;
    ListNode *node1,*node2;
    for(int i=1;i<m-1;i++)
        prenode1=prenode1->next;
    for(int i=1;i<n-1;i++)
        prenode2=prenode2->next;
    if(m>1) node1=prenode1->next;
    else node1=head;
    if(n>1) node2=prenode2->next;
    else node2=head;
    ListNode *cnt=head;
    ListNode *cur=head;
    ListNode *last=node2->next;
    ListNode *end=node2->next;
    if(m==1){
        while(cur!=end){
            cnt=cur;
            cur=cnt->next;
            cnt->next=last;
            last=cnt;
        }
        return node2;
    }
    else{
        cur=node1;
        while(cur!=end){
            cnt=cur;
            cur=cnt->next;
            cnt->next=last;
            last=cnt;
        }
        prenode1->next=last;
        return head;
    }
}