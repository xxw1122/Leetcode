class Solution:
    # @param nums, a list of integer
    # @param k, num of steps
    # @return nothing, please modify the nums list in-place.
    def revert(self, nums, start, end):
        mid = start + (end - start + 1) / 2
        for i in range(start, mid):
            cnt = nums[i]
            nums[i] = nums[end - (i - start)]
            nums[end - (i - start)] = cnt

    def rotate(self, nums, k):
        k = len(nums) - k % len(nums)
        self.revert(nums, 0, k-1)
        self.revert(nums, k, len(nums) - 1)
        self.revert(nums, 0, len(nums) - 1)