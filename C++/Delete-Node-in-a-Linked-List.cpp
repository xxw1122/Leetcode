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
    void deleteNode(ListNode* node) {
        if (node == NULL) return;
        if (node->next != NULL) {
        	ListNode* temp = node->next->next;
        	node->val = node->next->val;
        	node->next = temp;
        }
    }
};