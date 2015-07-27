# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @return a list of tree node
    def generate(self, left, right):
        if left > right:
            return [None]
        seq = []
        for i in range(left, right+1):
            lt = self.generate(left, i - 1)
            rt = self.generate(i + 1, right)
            for j in range(len(lt)):
                for k in range(len(rt)):
                    cnt = TreeNode(i)
                    cnt.left = lt[j]
                    cnt.right = rt[k]
                    seq.append(cnt)
        return seq
    def generateTrees(self, n):
        return self.generate(1, n)