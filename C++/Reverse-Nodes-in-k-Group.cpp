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
        for (int i = 0; i < k - 1; i ++) {
            if (head == NULL) return NULL;
            head = head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (getNode(head, k) != NULL) {
            stack<ListNode*> stk;
            ListNode *temp = head;
            for (int i = 0; i < k; i ++) {
                stk.push(temp);
                temp = temp->next;
            }
            head = temp;
            while (!stk.empty()) {
                temp = stk.top();
                stk.pop();
                cur->next = temp;
                cur = cur->next;
            }
        }
        cur->next = head;
        return dummy->next;
    }
};