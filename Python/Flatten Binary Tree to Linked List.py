#!/usr/bin/env python

from collections import deque
import collections

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# @param root, a tree node
# @return nothing, do it in place

def preorder(self, root, q):
    if root == None:
        return q
    q.append(root)
    q = self.preorder(root.left, q)
    q = self.preorder(root.right, q)
    return q

def flatten(self, root):
    q = []
    self.preorder(root, q)
    if len(q) == 0:
        return None
    root = q.pop(0)
    head = root
    root.left = None
    while len(q) > 0:
        root.right = q.pop(0)
        root = root.right
        root.left = None
    root.right = None
    return head