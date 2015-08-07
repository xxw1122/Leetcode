class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    	vector<string> RangeRes;
    	int cur = lower - 1;
    	for (int i = 0; i < nums.size(); i ++) {
    		if (nums[i] != cur + 1) {
    			if (nums[i] == cur + 2) {
    				RangeRes.push_back(to_string(cur + 1));
    			} else {
    				string str = to_string(cur + 1);
    				str += "->";
    				str += to_string(nums[i] - 1);
    				RangeRes.push_back(str);
    			}
    			cur = nums[i];
    		} else {
    			cur ++;
    		}
    		if (nums[i] == upper) break; 
    	}
    	if (cur < upper) {
    		if (cur + 1 == upper) {
    			RangeRes.push_back(to_string(cur + 1));
    		} else {
    			string str = to_string(cur + 1);
    			str += "->";
    			str += to_string(upper);
    			RangeRes.push_back(str);
    		}
    	}
    	return RangeRes;
    }
};