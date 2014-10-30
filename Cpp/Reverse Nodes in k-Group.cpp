#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseKGroup(ListNode *head, int k) {
    if(k<=1||head==NULL) return head;
    stack<ListNode*>st;
    ListNode *prenode=NULL,*node1=head,*node2=head,*pre;
    while(node1!=NULL){
        node2=node1;
        int cnt=k;
        while(node2!=NULL&&cnt--){
            node2=node2->next;
        }
        if(node2==NULL&&cnt!=0){
            if(prenode==NULL) return head;
            else{
                prenode->next=node1;
                return pre;
            }
        }
        else{
            int cur=k;
            while(cur--){
                st.push(node1);
                node1=node1->next;
            }
            while(!st.empty()){
                if(prenode==NULL){
                    prenode=st.top();
                    pre=st.top();
                    st.pop();
                }
                else{
                    prenode->next=st.top();
                    prenode=prenode->next;
                    st.pop();
                }
            }
        }
    }
    prenode->next=NULL;
    return pre;
}