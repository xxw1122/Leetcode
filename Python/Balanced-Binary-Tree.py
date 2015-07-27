class Solution:
    # @param root, a tree node
    # @return a boolean
    def depth(self, root):
        if root == None:
            return 0
        else:
            return max(self.depth(root.left), self.depth(root.right)) + 1
    def isBalanced(self, root):
        if root == None:
            return True
        else:
            if self.isBalanced(root.left) and self.isBalanced(root.right):
                return abs(self.depth(root.left) - self.depth(root.right)) <= 1
            else:
                return False