class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        int cur = 1;
        for (int i = 0; i < nums.size(); i ++) {
        	res[i] = cur;
        	cur *= nums[i];
        }
        cur = 1;
        for (int i = len - 1; i >= 0; i--) {
        	res[i] = res[i] * cur;
        	cur = cur * nums[i];
        }
        return res;
    }
};