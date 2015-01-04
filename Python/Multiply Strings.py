class Solution:
    # @param num1, a string
    # @param num2, a string
    # @return a string
    def multiply(self, num1, num2):
        if num1 == "0" or num2 == "0":
            return "0"
        len1 = len(num1)
        len2 = len(num2)
        num = [0] * (len1 + len2)
        for i in range(len1):
            for j in range(len2):
                num[i+j+1] += int(num1[i]) * int(num2[j])
        for i in range(len1 + len2):
            j = len1 + len2 - i - 1
            if num[j] >= 10:
                num[j-1] += num[j] / 10
                num[j] = num[j] % 10
        res = 0
        while res < len1 + len2:
            if num[res] != 0:
                break
            res += 1
        st = ""
        for i in range(res,len1 + len2):
            st += str(num[i])
        return st