class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	if (nums.empty()) return 0;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
        	int mid = left + (right - left) / 2;
        	if (nums[mid] >= target) right = mid;
        	else left = mid;
        }
        if (nums[left] >= target) return left;
        else if (nums[right] >= target) return right;
        return nums.size();
    }
};