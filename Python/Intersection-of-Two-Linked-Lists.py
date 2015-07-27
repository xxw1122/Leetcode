# Definition for singly-linked list.
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
        lenA = 0
        lenB = 0
        nodeA = headA
        nodeB = headB
        while nodeA != None:
            lenA += 1
            nodeA = nodeA.next
        while nodeB != None:
            lenB += 1
            nodeB = nodeB.next
        nodeA = headA
        nodeB = headB
        if lenA > lenB:
            for i in range(lenA - lenB):
                nodeA = nodeA.next
        else:
            for i in range(lenB - lenA):
                nodeB = nodeB.next
        while nodeA != None and nodeB != None:
            if nodeA == nodeB:
                return nodeA
            else:
                nodeA = nodeA.next
                nodeB = nodeB.next
        return None