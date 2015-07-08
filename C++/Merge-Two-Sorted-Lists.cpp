/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	// No Recursion
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        while (l1 != NULL && l2 != NULL) {
        	if (l1->val <= l2->val) {
        		cur->next = l1;
        		l1 = l1->next;
        	} else {
        		cur->next = l2;
        		l2 = l2->next;
        	}
        	cur = cur->next;
        }
        if (l1 != NULL) {
        	cur->next = l1;
        } else {
        	cur->next = l2;
        }
        return dummy->next;
    }
};

class Solution {
	//Recursion
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val <= l2->val) {
        	l1->next = mergeTwoLists(l1->next, l2);
        	return l1;
        } else {
        	l2->next = mergeTwoLists(l1, l2->next);
        	return l2;
        }
    }
};


