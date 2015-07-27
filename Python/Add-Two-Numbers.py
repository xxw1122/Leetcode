# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        seq = []
        while l1 != None and l2 != None:
            seq.append(l1.val + l2.val)
            l1 = l1.next
            l2 = l2.next
        while l1 != None:
            seq.append(l1.val)
            l1 = l1.next
        while l2 != None:
            seq.append(l2.val)
            l2 = l2.next
        cnt = 0
        head = None
        node = None
        while len(seq) > 0:
            ans = seq.pop(0)
            if head == None:
                head = ListNode((ans + cnt) % 10)
                cnt = (ans + cnt) / 10
                node = head
            else:
                node1 = ListNode((ans + cnt) % 10)
                cnt = (ans + cnt) / 10
                node.next = node1
                node = node1
        if cnt > 0:
            node1 = ListNode(cnt)
            node.next = node1
            node = node1
        node.next = None
        return head