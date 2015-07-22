class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0], cur = 1;
        for (int i = 1; i < nums.size(); i ++) {
        	if (nums[i] != res) {
        		cur --;
        		if (cur == 0) {
        			res = nums[i];
        			cur = 1;
        		}
        	} else {
        		cur ++;
        	}
        }
        return res;
    }
};