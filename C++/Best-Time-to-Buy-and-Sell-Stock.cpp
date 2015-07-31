class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int maxp = 0, minp = prices[0];
        for (int i = 0; i < prices.size(); i ++) {
            maxp = max(maxp, prices[i] - minp);
            minp = min(minp, prices[i]);
        }
        return maxp;
    }
};