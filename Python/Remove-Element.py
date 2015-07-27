class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        num = 0
        for i in range(len(A)):
            if A[i] != elem :
                A[num] = A[i]
                num = num + 1
        return num