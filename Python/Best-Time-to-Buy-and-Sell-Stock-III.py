class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        length=len(prices)
        if length==0: return 0
        f1=[0 for i in range(length)]
        f2=[0 for i in range(length)]

        minV=prices[0]; f1[0]=0
        for i in range(1,length):
            minV=min(minV, prices[i])
            f1[i]=max(f1[i-1],prices[i]-minV)

        maxV=prices[length-1]; f2[length-1]=0
        for i in range(length-2,-1,-1):
            maxV=max(maxV,prices[i])
            f2[i]=max(f2[i+1],maxV-prices[i])

        res=0
        for i in range(length):
            if f1[i]+f2[i]>res: res=f1[i]+f2[i]
        return res