# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return nothing
    def reorderList(self, head):
        seq = []
        node = head
        while node != None:
            seq.append(node)
            node = node.next
        node1 = None
        node = None
        cnt = 0
        while len(seq) > 0:
            if cnt == 0:
                if node1 == None:
                    node1 = seq.pop(0)
                    node = node1
                else:
                    node.next = seq.pop(0)
                    node = node.next
                cnt = 1
            elif cnt == 1:
                node.next = seq.pop()
                node = node.next
                cnt = 0
        if node != None:
            node.next = None
        return node1