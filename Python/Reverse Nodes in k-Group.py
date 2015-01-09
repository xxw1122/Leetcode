# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def reverseKGroup(self, head, k):
        if k < 2 or head == None:
            return head
        dummy = ListNode(0)
        p = dummy
        rhead = head
        while rhead != None:
            node = rhead
            for i in range(k-1):
                node = node.next
                if node == None:
                    p.next = rhead
                    return dummy.next
            node = node.next
            node1 = rhead
            seq = []
            while node1 != node:
                seq.append(node1)
                node1 = node1.next
                rhead = rhead.next
            while len(seq) > 0:
                p.next = seq.pop()
                p = p.next
        p.next = None
        return dummy.next