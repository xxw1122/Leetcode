class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, res = nums[0];
        for (int i = 0; i < nums.size(); i ++) {
            cur = max(cur + nums[i], nums[i]);
            res = max(res, cur);
        }
        return res;
    }
};