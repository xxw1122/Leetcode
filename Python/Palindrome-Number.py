class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        if x == 0:
            return True
        if x < 0:
            return False
        cnt = 1
        cur = 10
        for i in range(11):
            if x / cnt == 0:
                break
            cnt *= 10
        cnt = cnt / 10
        while cur <= cnt:
            left = x / cnt
            x = x % cnt
            right = x %cur
            if left != right:
                return False
            x = x/cur
            cnt = cnt / 100
        return True