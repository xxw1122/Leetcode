/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* getMidPre(ListNode* head) {
		if (head == NULL) return head;
		ListNode *slow = head, *fast = head->next, *prev = NULL;
		while (fast != NULL && fast->next != NULL) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		if (prev == NULL) return slow;
		return prev;
	}
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) {
        	TreeNode* root = new TreeNode(head->val);
        	return root;
        }
        ListNode* prev = getMidPre(head);
        TreeNode* root = new TreeNode(prev->next->val);
        ListNode* start = prev->next->next;
        prev->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(start);
        return root;
    }
};