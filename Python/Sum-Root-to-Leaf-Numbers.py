#!/usr/bin/env python

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def sumroot(self, root, s):
        if root == None:
            return 0
        elif root.left == None and root.right == None:
            return s * 10 + root.val
        else:
            return self.sumroot(root.left, s * 10 + root.val) + self.sumroot(root.right, s * 10 + root.val)
    def sumNumbers(self, root):
        return self.sumroot(root, 0)