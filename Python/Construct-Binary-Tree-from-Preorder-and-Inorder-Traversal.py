# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param preorder, a list of integers
    # @param inorder, a list of integers
    # @return a tree node
    def buildTree(self, preorder, inorder):
        len1 = len(preorder)
        if len1 == 0 or len1 != len(inorder):
            return None
        index = 0
        for i in range(len1):
            if preorder[0] == inorder[i]:
                index = i
                break
        root = TreeNode(preorder[0])
        root.left = self.buildTree(preorder[1:index+1], inorder[:index])
        root.right = self.buildTree(preorder[index+1:], inorder[index+1:])
        return root