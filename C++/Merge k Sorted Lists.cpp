/**
   Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
private:
    struct cmp{
    bool operator ()(const ListNode *a, const ListNode *b){
        return a->val > b->val;
    }
};
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for(int i = 0; i < n; i++){
            if(lists[i] != NULL) que.push(lists[i]);
        }
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while(!que.empty()){
            ListNode *node = que.top();
            que.pop();
            p->next = node;
            p = p->next;
            if(node->next != NULL) que.push(node->next)
        }
        return dummy->next;
    }
};