# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def rotateRight(self, head, k):
        if head == None or k == 0:
            return head
        node = head
        length = 0
        while node.next != None:
            node = node.next
            length += 1
        length += 1
        if length == 1 or k % length == 0:
            return head
        cnt = length - (k % length) - 1
        node1 = head
        for i in range(cnt):
            node1 = node1.next
        node2 = node1.next
        node1.next = None
        node.next = head
        return node2