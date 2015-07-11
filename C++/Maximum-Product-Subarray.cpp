class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxv = nums[0], minv = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
        	int x = maxv * nums[i];
        	int y = minv * nums[i];
        	int z = nums[i];
        	maxv = max(x, max(y, z));
        	minv = min(x, min(y, z));
        	res = max(res, maxv);
        }
        return res;
    }
};