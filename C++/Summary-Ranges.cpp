class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        int cur = nums[0], len = 1;
        for (int i = 1; i < nums.size(); i ++) {
        	if (nums[i] == nums[i - 1] + 1) {
        		len ++;
        	} else {
        		if (len == 1) {
        			res.push_back(to_string(cur));
        		} else {
        			string str = to_string(cur);
        			str += "->";
        			str += to_string(nums[i - 1]);
        			res.push_back(str);
        		}
        		len = 1;
        		cur = nums[i];
        	}
        }
        if (len == 1) {
        	res.push_back(to_string(cur));
        } else {
        	string str = to_string(cur);
        	str += "->";
        	str += to_string(nums.back());
        	res.push_back(str);
        }
        return res;
    }
};