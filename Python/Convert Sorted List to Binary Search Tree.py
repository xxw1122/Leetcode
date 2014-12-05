#!/usr/bin/env python

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a list node
    # @return a tree node
    def sortedListToBST(self, head):
        if head == None:
            return None
        slow = head
        fast = head
        prev = None
        while fast.next != None and fast.next.next != None:
            prev = slow
            fast = fast.next.next
            slow = slow.next
        if head == slow:
            head = None
        if prev != None:
            prev.next = None
        root = TreeNode(slow.val)
        left = self.sortedListToBST(head)
        right = self.sortedListToBST(slow.next)
        root.left = left
        root.right = right
        return root