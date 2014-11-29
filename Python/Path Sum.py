#!/usr/bin/env python

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def hasPathSum(self, root, sum):
    if root == None:
        return False
    if root.left == None and root.right == None:
        if root.val == sum:
            return True
        else:
            return False
    return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)