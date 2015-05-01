/**
 * Definition of ListNode
 */
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
     using constant space complexity.
    */
    ListNode *merge(ListNode *head1, ListNode *head2) {
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;
        ListNode *pre = new ListNode(-1), *cnt = pre;
        while (head1 != NULL && head2 != NULL) {
            if(head1->val < head2->val) {
                cnt->next = head1;
                head1 = head1->next;
            } else {
                cnt->next = head2;
                head2 = head2->next;
            }
            cnt = cnt->next;
        }
        if (head1 != NULL) {
            cnt->next = head1;
        } else if (head2 != NULL){
            cnt->next = head2;
        } else {
            cnt->next = NULL;
        }
        cnt = pre->next;
        delete pre;
        return cnt;
    }
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head, *cnt = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        return merge(sortList(slow), sortList(fast));
    }
};



