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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, num = 0;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *pre = new ListNode(-1), *cur = pre;
        while (l1 != NULL && l2 != NULL) {
        	num = l1->val + l2->val + carry;
        	carry = num / 10;
        	num = num % 10;
        	l1->val = num;
        	cur -> next = l1;
        	cur = cur->next;
        	l1 = l1->next;
        	l2 = l2->next;
        }
        while (l1 != NULL) {
        	num = l1->val + carry;
        	carry = num / 10;
        	num = num % 10;
        	l1->val = num;
        	cur->next = l1;
        	cur = cur->next;
        	l1 = l1->next;
        }
        while (l2 != NULL) {
        	num = l2->val + carry;
        	carry = num / 10;
        	num = num % 10;
        	l2->val = num;
        	cur->next = l2;
        	cur = cur->next;
        	l2 = l2->next;
        }
        if (carry > 0) {
        	ListNode *temp = new ListNode(carry);
        	cur->next = temp;
        }
        return pre->next;
    }
};






