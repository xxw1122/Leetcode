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
    int getlength(ListNode* head) {
        int length = 0;
        while (head != NULL) {
            length ++;
            head = head->next;
        }
        return length;        
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = getlength(head);
        if (len == 0) return head;
        if (k % len == 0) return head;
        k = k % len;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        for (int i = 0; i < k; i ++) {
            cur = cur->next;
        }
        ListNode *slow = dummy;
        while (cur->next != NULL) {
            cur = cur->next;
            slow = slow->next;
        }
        cur->next = dummy->next;
        dummy->next = slow->next;
        slow->next = NULL;
        return dummy->next;
    }
};