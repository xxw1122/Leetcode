class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        vector<int> leftp(len, 0);
        vector<int> rightp(len, 0);
        int cur = prices[0];
        for (int i = 1; i < len; i ++) {
            leftp[i] = max(prices[i] - cur, leftp[i - 1]);
            cur = min(prices[i], cur);
        }
        cur = prices[len - 1];
        for (int i = len - 2; i >= 0; i --) {
            rightp[i] = max(cur - prices[i], rightp[i + 1]);
            cur = max(prices[i], cur);
        }
        int res = 0;
        for (int i = 0; i < len; i ++) {
            res = max(res, leftp[i] + rightp[i]);
        }
        return res;
    }
};