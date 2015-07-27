# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def MakeTree(self, num, left, right):
        if left > right:
            return None
        mid = (left + right)/2
        root = TreeNode(num[mid])
        root.left = self.MakeTree(num, left, mid-1);
        root.right = self.MakeTree(num, mid+1, right);
        return root
    def sortedArrayToBST(self, num):
        if len(num) == 0:
            return None
        root = self.MakeTree(num, 0, len(num)-1)
        return root