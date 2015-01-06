class Solution:
    # @param ratings, a list of integer
    # @return an integer
    def candy(self, ratings):
        num = len(ratings)
        seq = [1] * num
        for i in range(1, num):
            if ratings[i] > ratings[i-1]:
                seq[i] = seq[i-1] + 1
        for i in range(1, num):
            j = num - i - 1
            if ratings[j] > ratings[j+1]:
                seq[j] = seq[j+1] + 1
        sum = 0
        for i in range(num):
            sum += seq[i]
        return sum