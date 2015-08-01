class Solution {
public:
	void reverse(vector<int>& nums, int left ,int right) {
		while (left < right) {
			swap(nums[left], nums[right]);
			left ++;
			right --;
		}
	}
    void rotate(vector<int>& nums, int k) {
    	int len = nums.size();
        if (k % len == 0) return;
        k = k % len;
        reverse(nums, 0, len - k - 1);
        reverse(nums, len - k, len - 1);
        reverse(nums, 0, len - 1);
    }
};