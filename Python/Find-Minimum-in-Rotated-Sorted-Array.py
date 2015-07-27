class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        n = len(num)
        left = 0
        right = n - 1
        while left < right and num[left] > num[right]:
            mid = (left + right) / 2
            if num[mid] < num[right]:
                right = mid
            else:
                left = mid + 1
        return num[left]