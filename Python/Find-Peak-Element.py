class Solution:
    # @param num, a list of integer
    # @return an integer
    def findPeakElement(self, num):
        if len(num) == 1:
            return 0
        left = 0
        right = len(num) - 1
        while left <= right:
            mid = (right - left) / 2 + left
            if mid == 0:
                if num[mid] > num[mid+1]:
                    return mid
                else:
                    left = mid + 1
            elif mid == len(num) - 1:
                if num[mid] > num[mid-1]:
                    return mid
                else:
                    right = mid - 1
            else:
                if num[mid] > num[mid-1] and num[mid] > num[mid+1]:
                    return mid
                elif num[mid] < num[mid-1]:
                    right = mid - 1
                elif num[mid] < num[mid+1]:
                    left = mid + 1