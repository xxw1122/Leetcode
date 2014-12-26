# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a tree node
    def inorder(self, root, seq):
        if root == None:
            return
        self.inorder(root.left)
        seq.append(root.val)
        self.inorder(root.right)
        return
    def recover(self, root, num1, num2):
        if root == None:
            return
        if root.val == num1:
            root.val = num2
        elif root.val == num2:
            root.val = num1
        self.recover(root.left, num1, num2)
        self.recover(root.right, num1, num2)
    def recoverTree(self, root):
        seq = []
        self.inorder(root, seq)
        index1 = 0
        index2 = 0
        for i in range(len(seq)-1):
            if seq[i] > seq[i+1]:
                index1 = i
                break
        for i in range(len(seq)-1):
            if seq[len(seq)-i-1] < seq[len(seq)-i-2]:
                index2 = len(seq) - i - 1
        index1 = seq[index1]
        index2 = seq[index2]
        self.recover(root, index1, index2)
        return