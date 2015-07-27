#include <map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


RandomListNode *copyRandomList(RandomListNode *head) {
    if(head == NULL) return NULL;
    map<int, RandomListNode*> mp;
    RandomListNode *prenode = new RandomListNode(head->label);
    RandomListNode *p = prenode, *rhead = head, *p1;
    while(rhead != NULL){
        RandomListNode *node = new RandomListNode(rhead->label);
        mp[rhead->label] = node;
        p->next = node;
        p = p->next;
        rhead = rhead->next;
    }
    p->next = NULL;
    rhead = prenode->next;
    p1 = head;
    while(rhead != NULL){
        if(p1->random == NULL){
            rhead->random = NULL;
        }
        else{
            int cnt = p1->random->label;
            rhead->random = mp[cnt];
        }
        rhead = rhead->next;
        p1 = p1->next;
    }
    return prenode->next;
}