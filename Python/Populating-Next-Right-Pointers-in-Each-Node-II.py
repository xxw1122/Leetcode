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
        if root == None:
            return None
        while root.left == None and root.right == None:
            root = root.next
            if root == None:
                return root
        if root.left != None:
            return root.left
        else:
            return root.right

    def connectTree(self, root, lchild, rchild):
        if lchild != None and rchild != None:
            lchild.next = rchild
            rchild.next = self.findnextnode(root.next)
            self.connectTree(rchild, rchild.left, rchild.right)
            self.connectTree(lchild, lchild.left, lchild.right)
        elif lchild != None and rchild == None:
            lchild.next = self.findnextnode(root.next)
            self.connectTree(lchild, lchild.left, lchild.right)
        elif rchild != None and lchild == None:
            rchild.next = self.findnextnode(root.next)
            self.connectTree(rchild, rchild.left, rchild.right)
        return

    def connect(self, root):
        if root == None:
            return
        self.connectTree(root, root.left, root.right)