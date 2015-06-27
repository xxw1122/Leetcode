class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res, cnt;
        for (int i = 0; i < nums.size(); i ++) {
        	if (nums[i] * 2 == target) {
        		cnt.push_back(i + 1);
        	} else {
        		hash[nums[i]] = i + 1;
        	}
        }
        if (cnt.size() >= 2) {
        	res.push_back(cnt[0]);
        	res.push_back(cnt[1]);
        	return res;
        }
        for (int i = 0; i < nums.size(); i ++) {
        	if (hash.find(target - nums[i]) != hash.end()) {
        		int temp = hash[target - nums[i]];
        		res.push_back(min(temp, i + 1));
        		res.push_back(max(tmep, i + 1));
        		return res;
        	}
        }
        return res;
    }
};