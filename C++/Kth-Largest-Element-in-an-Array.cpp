class Solution {
public:
    int FindKth(vector<int> &nums, int start, int end, int k) {
        if (start == end) return nums[start];
        int left = start + 1, right = end, cur = nums[start];
        while (left <= right) {
            while (left <= right && nums[left] < cur) left ++;
            while (left <= right && nums[right] >= cur) right --;
            if (left < right) {
                swap(nums[left], nums[right]);
            }
        }
        swap(nums[start], nums[right]);
        if (right - start + 1 == k) return nums[right];
        else if (right - start + 1 > k) return FindKth(nums, start, right - 1, k);
        else return FindKth(nums, right + 1, end, k - (right - start + 1));
    }
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        return FindKth(nums, 0, len - 1, len - k + 1);
    }
};