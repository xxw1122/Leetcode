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
    ListNode* getMid(ListNode* head) {
        if (head == NULL) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode *head) {
        ListNode *cur = NULL;
        while (head != NULL) {
            ListNode *temp = head->next;
            head->next = cur;
            cur = head;
            head = temp;
        }
        return cur;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode *mid = getMid(head);        
        ListNode *start = mid->next;
        mid->next = NULL;
        ListNode *n_start = reverse(start);
        ListNode *pre = new ListNode(0), *cur = pre;
        while (head != NULL || n_start != NULL) {
            if (head != NULL) {
                cur->next = head;
                cur = cur->next;
                head = head->next;
            }
            if (n_start != NULL) {
                cur->next = n_start;
                n_start = n_start->next;
                cur = cur->next;
            }
        }
        cur->next = NULL;
    }
};