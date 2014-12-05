# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param x, an integer
    # @return a ListNode
    def partition(self, head, x):
        head1 = None
        head2 = None
        node1 = None
        node2 = None
        node = head
        while node != None:
            if node.val < x:
                if head1 == None:
                    head1 = node
                    node1 = node
                else:
                    node1.next = node
                    node1 = node1.next
            else:
                if head2 == None:
                    head2 = node
                    node2 = node
                else:
                    node2.next = node
                    node2 = node2.next
            node = node.next
        if head1 != None:
            node1.next = head2
        if node2 != None:
            node2.next = None
        if head1 != None:
            return head1
        else:
            return head2