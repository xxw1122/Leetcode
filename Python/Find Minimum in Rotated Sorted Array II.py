class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        left = 0
        right = len(num) - 1
        while left < right and num[left] >= num[right]:
            mid = (left + right) / 2
            if num[mid] > num[left]:
                left = mid + 1
            elif num[mid] < num[right]:
                right = mid
            else:
                left += 1
        return num[left]