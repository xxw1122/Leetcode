class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if len(prices) == 0:
            return 0
        minv = prices[0]
        profit = 0
        for i in range(1, len(prices)):
            if prices[i] - minv > profit:
                profit = prices[i] - minv
            if prices[i] < minv:
                minv = prices[i]
        return profit
