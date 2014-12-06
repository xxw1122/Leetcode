#!/usr/bin/env python

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def insertionSortList(self, head):
    if head == None or head.next == None:
        return head
    node = head.next
    tail = head
    tail.next = None
    while node != None:
        node1 = node.next
        if node.val <= head.val:
            node.next = head
            head = node
        elif node.val > tail.val:
            tail.next = node
            tail = node
        else:
            prev = None
            node2 = head
            while node2 != None and node2.val <= node.val:
                prev = node2
                node2 = node2.next
            prev.next =node
            node.next = node2
        node = node1
    tail.next = None
    return head