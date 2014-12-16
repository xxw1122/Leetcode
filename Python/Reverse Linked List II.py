#!/usr/bin/env python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param m, an integer
    # @param n, an integer
    # @return a ListNode
    # m = 2, n = 4
    def reverseBetween(self, head, m, n):
        if m == n:
            return head
        start = head
        end = head
        prenode = None
        for i in range(m - 1):
            prenode = start
            start = start.next
            end = end.next
        for i in range(n - m):
            end = end.next
        new_end = end.next
        while start != end:
            node = start.next
            start.next = new_end
            new_end = start
            start = node
        if prenode == None:
            prenode = start
            start.next = new_end
            return prenode
        else:
            start.next = new_end
            prenode.next = start
            return head