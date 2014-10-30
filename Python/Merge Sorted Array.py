class Solution:
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing
    def merge(self, A, m, B, n):
        C = []
        i = 0
        j = 0
        while i < m and j < n:
            if A[i] < B[j]:
                C.append(A[i])
                i = i + 1
            else:
                C.append(B[j])
                j = j + 1
        while i < m:
            C.append(A[i])
            i = i + 1
        while j < n:
            C.append(B[j])
            j = j + 1
        for k in range(m + n):
            A[k] = C[k]