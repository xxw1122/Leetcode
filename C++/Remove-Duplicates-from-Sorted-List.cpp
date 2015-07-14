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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode *cur = head, *cnt = head->next;
        while (cnt != NULL) {
            if (cnt->val != cur->val) {
                cur->next = cnt;
                cur = cur->next;
            }
            cnt = cnt->next;
        }
        cur->next = NULL;
        return head;
    }
};