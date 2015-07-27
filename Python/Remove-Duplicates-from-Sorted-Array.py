class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        length = len(A)
        if length <= 0:
            return 0
        num = 1;
        cnt = A[0]
        for i in range(1, length):
            if A[i] != cnt:
                cnt = A[i]
                A[num] = cnt
                num = num + 1
        return num