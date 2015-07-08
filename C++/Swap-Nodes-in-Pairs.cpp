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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(0), *prev = dummy;
        while (head != NULL && head->next != NULL) {
            ListNode *temp1 = head, *temp2 = head->next;
            head = head->next->next;
            prev->next = temp2;
            prev = prev->next;
            prev->next = temp1;
            prev = prev->next;
        }
        prev->next = head;
        return dummy->next;
    }
};