#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode *node1=l1,*node2=l2;
    ListNode *prenode=NULL,*pre;
    int d=0;
    while(node1!=NULL&&node2!=NULL){
        if(prenode==NULL){
            ListNode *root=new ListNode(sizeof(ListNode));
            int cnt=d+node1->val+node2->val;
            d=cnt/10;
            root->val=cnt%10;
            prenode=root;
            pre=root;
        }
        else{
            int cnt=d+node1->val+node2->val;
            d=cnt/10;
            ListNode *root=new ListNode(sizeof(ListNode));
            root->val=cnt%10;
            prenode->next=root;
            prenode=prenode->next;
        }
        node1=node1->next;
        node2=node2->next;
    }
    if(node1==NULL){
        while(node2!=NULL){
            int cnt=d+node2->val;
            d=cnt/10;
            ListNode *root=new ListNode(sizeof(ListNode));
            root->val=cnt%10;
            prenode->next=root;
            prenode=prenode->next;
            node2=node2->next;
        }
    }
    else if(node2==NULL){
        while(node1!=NULL){
            int cnt=d+node1->val;
            d=cnt/10;
            ListNode *root=new ListNode(sizeof(ListNode));
            root->val=cnt%10;
            prenode->next=root;
            prenode=prenode->next;
            node1=node1->next;
        }
    }
    if(d>0){
        ListNode *root=new ListNode(sizeof(ListNode));
        root->val=d;
        prenode->next=root;
        prenode=prenode->next;
    }
    prenode->next=NULL;
    return pre;
}