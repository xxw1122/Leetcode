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
	int getLength(ListNode *head) {
		int res = 0;
		while (head != NULL) {
			head = head->next;
			res ++;
		}
		return res;
	}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA), lenB = getLength(headB);
        int temp;
        if (lenA < lenB) {
        	temp = lenB - lenA;
        	while (temp --) {
        		headB = headB->next;
        	}
        } else {
        	temp = lenA - lenB;
        	while (temp --) {
        		headA = headA->next;
        	}
        }
        while (headA != NULL && headB != NULL) {
        	if (headA == headB) return headA;
        	headA = headA->next;
        	headB = headB->next;
        }
        return NULL;
    }
};