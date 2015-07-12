class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
        	int mid = left + (right - left) / 2;
        	if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
        	else if (nums[mid] < nums[mid - 1]) right = mid;
        	else left = mid;
        }
        if (nums[left] < nums[right]) return right;
        else return left;
    }
};