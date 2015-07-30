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
        ListNode *pre = new ListNode(0), *cur = pre;
        while (head != NULL) {
            ListNode *temp = head;
            int count = 0;
            while (temp != NULL && temp->val == head->val) {
                temp = temp->next;
                count ++;
            }
            if (count == 1) {
                cur->next = head;
                cur = cur->next;
            }
            head = temp;
        }
        cur->next = NULL;
        return pre->next;
    }
};