class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num):
        result = num[0]
        times = 1
        for i in range(1, len(num)):
            if times == 0:
                result = num[i]
                times = 1
            elif num[i] == result:
                times += 1
            elif num[i] != result:
                times -= 1
        return result