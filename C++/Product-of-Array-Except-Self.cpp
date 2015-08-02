class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        for (int i = 1; i < len; i ++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int cur = 1;
        for (int i = len - 2; i >= 0; i --) {
            cur = cur * nums[i + 1];
            res[i] = res[i] * cur;
        }
        return res;
    }
};