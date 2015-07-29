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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre = new ListNode(0), *cur = pre;
        while (head != NULL) {
            if (head->val != val) {
                cur->next = head;                
                cur = cur->next;
            }
            head = head->next;                      
        }
        cur->next = NULL;
        return pre->next;
    }
};