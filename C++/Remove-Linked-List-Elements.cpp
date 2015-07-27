/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre = new ListNode(-1), *cnt = pre;
        while (head != NULL) {
            if (head->val != val) {
                cnt->next = head;
                cnt = cnt->next;
            }
            head = head->next;
        }
        cnt->next = NULL;
        head = pre->next;
        delete pre;
        return head;
    }
};