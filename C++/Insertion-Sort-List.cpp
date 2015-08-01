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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *pre = new ListNode(0);
        while (head != NULL) {
            ListNode *temp = head->next;
            ListNode *p = pre;
            while (p->next != NULL && p->next->val < head->val) {
                p = p->next;
            }
            ListNode *cnt = p->next;
            p->next = head;
            head->next = cnt;
            head = temp;
        }
        return pre->next;
    }
};