# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def minDepth(self, root):
        if root == None:
            return 0
        if root.left != None and root.right != None:
            return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
        elif root.left == None and root.right == None:
            return 1
        elif root.left == None:
            return self.minDepth(root.right) + 1
        elif root.right == None:
            return self.minDepth(root.left) + 1