# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def inorder(self, root, seq):
        if root == None:
            return
        self.inorder(root.left, seq)
        seq.append(root.val)
        self.inorder(root.right, seq)
    def isValidBST(self, root):
        seq = []
        self.inorder(root, seq)
        length = len(seq)
        for i in range(1, length):
            if seq[i] <= seq[i-1]:
                return False
        return True