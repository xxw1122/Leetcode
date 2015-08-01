/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    // can not modify the original List
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode *pre = new RandomListNode(0), *cur = pre;
        RandomListNode *p = head;
        while (p != NULL) {
            RandomListNode* temp = p->next;
            RandomListNode* node = new RandomListNode(p->label);
            p->next = node;
            node->next = temp;
            p = temp;
        }
        RandomListNode *cnt = head;
        while (cnt != NULL) {
            if (cnt->random != NULL) cnt->next->random = cnt->random->next;
            else cnt->next->random = NULL;
            cnt = cnt->next->next;
        }
        while (head != NULL) {
            RandomListNode* temp = head->next->next;
            cur->next = head->next;
            cur = cur->next;
            head->next = temp;
            head = temp;
        }
        cur->next = NULL;
        return pre->next;
    }
};