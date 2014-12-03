#!/usr/bin/env python


#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# @return a ListNode
def removeNthFromEnd(self, head, n):
    node1 = head
    for i in range(n):
        node1 = node1.next
    if node1 == None:
        return head.next
    node2 = head
    while node1.next != None:
        node1 = node1.next
        node2 = node2.next
    node2.next = (node2.next).next
    return head