class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (k == 0 || nums.empty()) return res;
        deque<int> dq;
        for (int i = 0; i < k - 1; i ++) {
        	while (!dq.empty() && nums[i] >= nums[dq.front()]) {
        		dq.pop_front();
        	}
        	dq.push_front(i);
        }
        for (int i = k - 1; i < nums.size(); i ++) {
        	while (!dq.empty() && nums[i] >= nums[dq.front()]) {
        		dq.pop_front();
        	}
        	dq.push_front(i);
        	res.push_back(nums[dq.back()]);
        	while (!dq.empty() && i - dq.back() >= k - 1) {
        		dq.pop_back();
        	}
        }
        return res;
    }
};