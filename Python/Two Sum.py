class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        d = {}
        for i in range(len(num)):
            if num[i] not in d:
                d[num[i]] = []
            d[num[i]].append(i)
        index1 = 0
        index2 = 0
        sorted(num)
        if target % 2 == 0 and (target / 2) in d and len(d[target/2]) == 2:
            index1 = d[target/2][0]
            index2 = d[target/2][1]
        else:
            for item in num:
                cnt = target - item
                if cnt in d and cnt != item:
                    index1 = d[item][0]
                    index2 = d[cnt][0]
                    break
        if index1 > index2:
            index1, index2 = index2, index1
        seq = (index1+1, index2+1)
        return seq