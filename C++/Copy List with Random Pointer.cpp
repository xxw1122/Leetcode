#include <map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


RandomListNode *copyRandomList(RandomListNode *head) {
    if(head==NULL) return NULL;
    map<int,RandomListNode*>st;
    RandomListNode* root=new RandomListNode(sizeof(RandomListNode));
    int flag=0;
    RandomListNode *node=NULL;
    RandomListNode *node1=head;
    while(node1!=NULL){
        if(flag==0){
            root->label=node1->label;
            st.insert(make_pair(root->label,root));
            node=root;
            flag=1;
        }
        else{
            RandomListNode *node3=new RandomListNode(sizeof(RandomListNode));
            node3->label=node1->label;
            node->next=node3;
            node=node3;
            st.insert(make_pair(node3->label,node3));
        }
        node1=node1->next;
    }
    node->next=NULL;
    node1=head,node=root;
    while(node1!=NULL){
        if(node1->random==NULL){
            node->random=NULL;
        }
        else{
            int cnt=node1->random->label;
            node->random=st[cnt];
        }
        node=node->next;
        node1=node1->next;
    }
    return root;
}