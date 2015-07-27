# @iFighting

# Definition for singly-linked list.
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        node1=head
        node2=head
        while node2 != None:
            node1=node1.next
            node2=node2.next
            if node2 == None:
                return False
            node2=node2.next;
            if(node2==node1):
                return True
        return False