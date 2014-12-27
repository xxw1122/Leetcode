# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param inorder, a list of integers
    # @param postorder, a list of integers
    # @return a tree node
    def buildTree(self, inorder, postorder):
        len1 = len(inorder)
        if len1 == 0:
            return None
        index = 0
        for i in range(len1):
            if inorder[i] == postorder[-1]:
                index = i
                break
        root = TreeNode(postorder[-1])
        root.left = self.buildTree(inorder[:index], postorder[:index])
        root.right = self.buildTree(inorder[index+1:], postorder[index:len1-1])
        return root
