class Solution:
    # @return a string
    def convertToTitle(self, num):
        s = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        st = ''
        while num > 0:
            cnt = num % 26
            st += s[(cnt + 25) % 26]
            num = num/26
            if cnt == 0:
                num -= 1
        return st[::-1]