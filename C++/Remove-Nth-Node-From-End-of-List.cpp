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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        int count = 0;
        while (count < n) {
            prev = prev->next;
            count ++;
        }
        ListNode *cur = dummy;
        while (prev->next != NULL) {
            prev = prev->next;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return dummy->next;
    }
};