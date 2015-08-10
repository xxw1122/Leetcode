/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */

// time complexity O(n), space complexity O(1)

public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    public int getDepth(TreeNode root) {
    	if (root == null) return 0;
    	int left = getDepth(root.left), right = getDepth(root.right);
    	if (left == -1 || right == -1 || Math.abs(left - right) > 1) return -1;
    	return max(left, right) + 1;
    }
    public boolean isBalanced(TreeNode root) {
        // write your code here
        return getDepth(root) != -1;
    }
}
