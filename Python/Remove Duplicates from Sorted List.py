#!/usr/bin/env python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        if head == None:
            return None
        node1 = head
        node2 = head.next
        while node2 != None :
            if node2.val != node1.val:
                node1.next = node2
                node1 = node1.next
                node2 = node2.next
            else:
                node2 = node2.next

        node1.next=None
        return head