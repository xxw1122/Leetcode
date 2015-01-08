class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
        symbol = 1
        if dividend < 0 and divisor < 0:
            dividend = - dividend
            divisor = - divisor
        elif dividend < 0:
            dividend = - dividend
            symbol = -1
        elif divisor < 0:
            divisor = - divisor
            symbol = -1
        cnt = divisor
        ans = 1
        res = 0
        while dividend > 0:
            if dividend < divisor:
                break
            while cnt < dividend and cnt + cnt < dividend:
                cnt += cnt
                ans += ans
            dividend -= cnt
            res += ans
            ans = 1
            cnt =divisor
        if res * symbol > 2147483647:
            return 2147483647
        else:
            return res * symbol