struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if (head == NULL || head ->next == NULL) return false;
        ListNode *node1 = head, *node2 = head;
        node1 = node1->next;
        node2 = (node2->next)->next;
        if (node2 == NULL) return false;
        while (node1 != node2) {
            node1 = node1->next;
            node2 = node2->next;
            if (node2 == NULL) return false;
            node2 = node2->next;
            if (node2 == NULL) return false;
        }
        return true;
    }
};