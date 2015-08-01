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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head, *fast = head->next;
        int count = 1;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            count ++;
            if (slow == fast) break;            
        }
        if (slow != fast) return NULL;
        ListNode *cur = head;
        for (int i = 0; i < count; i ++) {
        	cur = cur->next;
        }
        while (cur != head) {
        	cur = cur->next;
        	head = head->next;
        }
        return cur;
    }
};