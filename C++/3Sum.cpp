class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        int index = 0;
        while (index + 2 < nums.size()) {
        	int left = index + 1, right = nums.size() - 1;
        	while (left < right) {
        		if (nums[left] + nums[right] == -nums[index]) {
        			vector<int> cur;
        			cur.push_back(nums[index]);
        			cur.push_back(nums[left]);
        			cur.push_back(nums[right]);
        			res.push_back(cur);
        			int leftv = nums[left++], rightv = nums[right--];
        			while (left < right && nums[left] == leftv) left ++;
        			while (left < right && nums[right] == rightv) right --;
        		}
        		else if (nums[left] + nums[right] > -nums[index]) {
        			right --;
        		} else {
        			left ++;
        		}
        	}
        	int temp = nums[index++];
        	while (index + 2 < nums.size() && nums[index] == temp) index ++;
        }
        return res;
    }
};