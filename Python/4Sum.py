class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, num, target):
        n = len(num)
        num.sort()
        res = []
        for i in range(n-3):
            if i > 0 and num[i] == num[i-1]:
                continue
            for j in range(i+1, n-2):
                if j > i + 1 and num[j] == num[j-1]:
                    continue
                x = j + 1
                y = n - 1
                while x < y:
                    s = num[i] + num[j] + num[x] + num[y]
                    if s == target:
                        res.append([num[i], num[j], num[x], num[y]])
                        x += 1
                        y -= 1
                        while x < y and num[x] == num[x-1]:
                            x += 1
                        while x < y and num[y] == num[y+1]:
                            y -= 1
                    elif s < target:
                        x += 1
                    else:
                        y -= 1
        return res