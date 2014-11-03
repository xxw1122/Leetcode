class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        tag = -1
        for i in range(len(num) - 1):
            if num[i] > num[i+1]:
                tag = i + 1
                break
        if tag != -1:
            return num[tag]
        else:
            return num[0]