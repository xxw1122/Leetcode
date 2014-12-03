#!/usr/bin/ERNV python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        if head == None or head.next == None:
            return head
        node = head.next.next
        root = head.next
        root.next = head
        tail = head
        while node != None:
            if node.next != None:
                node1 = node
                node2 = node.next
                node = node.next.next
                tail.next = node2
                node2.next = node1
                tail = node1
            else:
                tail.next = node
                tail = node
                break
        tail.next = None
        return root