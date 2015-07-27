#!/usr/bin/env python

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

class Solution:
    # @param root, a tree node
    # @return nothing
    def findnextnode(self, root):
        if root.next == None:
            return None
        return root.next.left;

    def connect(self, root):
        if root == None:
            return
        if root.left == None:
            return
        root.left.next = root.right;
        root.right.next = self.findnextnode(root)
        self.connect(root.left);
        self.connect(root.right);