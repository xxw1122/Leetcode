#!/usr/bin/env python

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def findmin(self, A, target):
        left = 0
        right = len(A) - 1
        while left <= right:
            mid = (left + right) / 2
            if A[mid] == target:
                if mid == 0:
                    return 0
                elif mid > 0 and A[mid-1] < target:
                    return mid
                else:
                    right = mid - 1
            elif A[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        return -1
    def findmax(self, A, target):
        left = 0
        right = len(A) - 1
        while left <= right:
            mid = (left + right) / 2
            if A[mid] == target:
                if mid == right:
                    return right
                elif mid < right and A[mid+1] > target:
                    return mid
                else:
                    left = mid + 1
            elif A[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
    def searchRange(self, A, target):
        seq = []
        left = self.findmin(A, target)
        right = self.findmax(A, target)
        seq.append(left)
        seq.append(right)
        return seq