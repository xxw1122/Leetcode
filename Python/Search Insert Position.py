#!/usr/bin/env python

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        left = 0
        right = len(A) - 1
        while left <= right:
            mid = (left + right)/2
            if A[mid] == target:
                return mid
            elif A[mid] < target:
                if mid == right:
                    return mid + 1
                elif A[mid+1] > target:
                    return mid+1
                else:
                    left = mid + 1
            elif A[mid] > target:
                if mid == 0:
                    return 0
                elif A[mid-1] < target:
                    return mid
                else:
                    right = mid - 1;