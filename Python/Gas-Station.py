class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        if sum(gas) < sum(cost):
            return -1
        num = len(gas)
        diff = 0
        index = 0
        for i in range(num):
            if diff + gas[i] < cost[i]:
                diff = 0
                index = i + 1
            else:
                diff += gas[i] - cost[i]
        return index