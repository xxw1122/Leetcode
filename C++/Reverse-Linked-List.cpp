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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode *cur = head, *cnt = NULL;
        while (cur != NULL) {
            ListNode *temp = cur->next;
            cur->next = cnt;
            cnt = cur;
            cur = temp;
        }
        return cnt;
    }
};