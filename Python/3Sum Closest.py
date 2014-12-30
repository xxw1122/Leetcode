class Solution:
    # @return an integer
    def threeSumClosest(self, num, target):
        num.sort()
        res = num[0] + num[1] + num[2]
        for i in range(len(num)-2):
            left = i + 1
            right = len(num) - 1
            while left < right:
                s = num[i] + num[left] + num[right]
                if abs(s-target) < abs(res-target):
                    res = s
                if s == target:
                    return s
                elif s < target:
                    left += 1
                else:
                    right -= 1
        return res