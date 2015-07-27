class Solution:
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
        leftmosthigh = [0 for i in range(len(A))]
        leftmax = 0
        for i in range(len(A)):
            if A[i] > leftmax: leftmax = A[i]
            leftmosthigh[i] = leftmax
        sum = 0
        rightmax = 0
        for i in reversed(range(len(A))):
            if A[i] > rightmax: rightmax = A[i]
            if min(rightmax, leftmosthigh[i]) > A[i]:
                sum += min(rightmax, leftmosthigh[i]) - A[i]
        return sum