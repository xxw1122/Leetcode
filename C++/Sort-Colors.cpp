class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right && nums[left] < 2) {
                left ++;
            }
            while (left < right && nums[right] == 2) {
                right --;
            }
            if (left < right) {
                swap(nums[left], nums[right]);
            }
        }
        left = 0;
        while (left < right) {
            while (left < right && nums[left] == 0) {
                left ++;
            }
            while (left < right && nums[right] != 0) {
                right --;
            }
            if (left < right) {
                swap(nums[left], nums[right]);
            }
        }
    }
};