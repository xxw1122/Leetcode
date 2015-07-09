/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getNode(ListNode *head, int k) {
        for (int i = 0; i < k; i ++) {
            if (head == NULL) return NULL;
            head = head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy.next = head, head = dummy;
        ListNode *cur = dummy;
        while (getNode(head) != NULL) {
            stack<ListNode*> stk;
            ListNode *temp = head;
            for (int i = 0; i < k; i ++) {
                temp = temp->next;
                stk.push(temp);
            }
        }
    }
};