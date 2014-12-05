#!/usr/bin/env python

import copy

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def makepathSum(self, root, sum, seq, cnt):
        if root == None:
            return seq
        if root.left == None and root.right == None and root.val == sum:
            cnt.append(root.val)
            seq.append(copy.copy(cnt))
            cnt.pop()
            return seq
        if root.left != None:
            cnt.append(root.val)
            seq = self.makepathSum(root.left, sum - root.val, seq, cnt)
            cnt.pop()
        if root.right != None:
            cnt.append(root.val)
            seq = self.makepathSum(root.right, sum - root.val, seq, cnt)
            cnt.pop()
        return seq
    def pathSum(self, root, sum):
        seq = []
        cnt = []
        seq = self.makepathSum(root, sum, seq, cnt)
        return seq