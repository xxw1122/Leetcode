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
	ListNode* getMid(ListNode *head) {
		ListNode *slow = head, *fast = head->next;
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
	ListNode *reverse(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *cur = NULL;
		while (head != NULL) {
			ListNode *temp = head->next;
			head->next = cur;
			cur = head;
			head = temp;
		}
		return cur;
	}
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *mid = getMid(head);
        ListNode *start = mid->next;
        mid->next = NULL;
        ListNode *n_start = reverse(start);
        while (head != NULL && n_start != NULL) {
        	if (head->val !=  n_start->val) return false; 
        	head = head->next;
        	n_start = n_start->next;
        }
        return true;
    }
};