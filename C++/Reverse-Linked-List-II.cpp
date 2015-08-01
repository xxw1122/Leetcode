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
    ListNode* reverse(ListNode* head) {
        ListNode* res = NULL;
        while (head != NULL) {
            ListNode* temp = head->next;
            head->next = res;
            res = head;
            head = temp;
        }
        return res;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode *pre = new ListNode(0), *cur = pre;
        pre->next = head;
        for (int i = 1; i < m; i ++) {
            cur = cur->next;
        }
        ListNode* pre_start = cur;
        for (int i = 0; i < n - m; i ++) {
            cur = cur->next;
        }
        ListNode *pre_end = cur, *start = pre_start->next;
        ListNode* next_end = cur->next->next;
        cur->next->next = NULL;
        ListNode *new_start = reverse(start);
        pre_start->next = new_start;
        cur = pre;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = next_end;
        return pre->next;
    }
};