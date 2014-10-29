# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        flag = 0
        while l1 != None and l2 != None:
            if l1.val < l2.val:
                if flag == 0:
                    head = l1
                    node = l1
                    flag = 1
                else:
                    node.next = l1
                    node = node.next
                l1 = l1.next
            else:
                if flag == 0:
                    head = l2
                    node = l2
                    flag = 1
                else:
                    node.next = l2
                    node = node.next
                l2 = l2.next
        if l1 == None:
            if flag == 0:
                head = l2
            else:
                node.next = l2
        else:
            if flag == 0:
                head = l1
            else:
                node.next = l1
        return head