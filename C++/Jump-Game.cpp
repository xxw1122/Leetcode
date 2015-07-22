class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxlen = 0, cur = 0;
        while (cur < nums.size() && cur <= maxlen) {
        	maxlen = max(maxlen, cur + nums[cur]);
        	if (maxlen >= nums.size() - 1) return true;
        	cur ++;
        }
        return false;
    }
};