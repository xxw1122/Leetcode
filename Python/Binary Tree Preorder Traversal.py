#!/usr/bin/env python

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def Traversal(self,root,res):
        if root != None:
            res.append(root.val)
            self.Traversal(root.left,res);
            self.Traversal(root.right,res);
        return
    def preorderTraversal(self, root):
        res=[]
        self.Traversal(root,res)
        return res