#!/usr/bin/env python

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        # @param root, a tree node
        # @return a boolean
def symmetric(self, root1, root2):
    if root1 == None and root2 == None:
        return True
    elif root1 == None or root2 == None:
        return False
    if root1.val != root2.val:
        return False
    return self.symmetric(root1.left, root2.right) and self.symmetric(root1.right, root2.left)

def isSymmetric(self, root):
    if root == None:
        return True
    elif root.left == None and root.right == None:
        return True
    elif root.left != None and root.right != None:
        return self.symmetric(root.left, root.right)
    else:
        return False