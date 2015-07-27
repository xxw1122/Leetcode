# Definition for singly-linked list with a random pointer.
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        d = {}
        dummy = RandomListNode(0)
        p = dummy
        n_head = head
        while n_head != None:
            node = RandomListNode(n_head.label)
            p.next = node
            d[node.label] = node
            p = p.next
            n_head = n_head.next
        p.next = None
        n_head = head
        r_head = dummy.next
        while r_head != None:
            if n_head.random == None:
                r_head.random = None
            else:
                cnt = n_head.random.label
                r_head.random = d[cnt]
            r_head = r_head.next
            n_head = n_head.next
        return dummy.next