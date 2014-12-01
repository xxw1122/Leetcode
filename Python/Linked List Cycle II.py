#!/usr/bin/env python
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# @param head, a ListNode
# @return a list node
def detectCycle(self, head):
    if head == None:
        return None
    node1 = head
    node2 = head
    while node1 != None:
        node2 = node2.next
        node1 = node1.next
        if node1 == None:
            return None
        node1 = node1.next
        if node2 == node1:
            break
    if node1 == None:
        return None
    node2 = head
    while node2 != node1:
        node1 = node1.next
        node2 = node2.next
    return node2