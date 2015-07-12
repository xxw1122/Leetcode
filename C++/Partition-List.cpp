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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode(0), *dummy2 = new ListNode(0);
        ListNode *leftcur = dummy1, *rightcur = dummy2;
        while (head != NULL) {
            if (head->val < x) {
                leftcur->next = head;
                leftcur = leftcur->next;
            } else {
                rightcur->next = head;
                rightcur = rightcur->next;
            }
            head = head->next;
        }
        rightcur->next = NULL;
        leftcur->next = dummy2->next;
        return dummy1->next;
    }
};