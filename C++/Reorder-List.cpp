#include <deque>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void reorderList(ListNode *head) {
    if(head==NULL||head->next==NULL) return;
    ListNode *node=head;
    deque<ListNode*>st;
    node=node->next;
    while(node!=NULL){
        st.push_back(node);
        node=node->next;
    }
    ListNode* prenode=head;
    while(st.size()>=2){
        prenode->next=st.back();
        st.pop_back();
        prenode=prenode->next;
        prenode->next=st.front();
        st.pop_front();
        prenode=prenode->next;
    }
    if(st.size()==1){
        prenode->next=st.back();
        st.pop_back();
        prenode=prenode->next;
        prenode->next=NULL;
    }
    else{
        prenode->next=NULL;
    }
    return;
}