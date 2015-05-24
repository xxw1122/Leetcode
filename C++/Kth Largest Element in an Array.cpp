#include <vector>

class Solution {
public:
    int findk(vector<int> &nums, int start, int end, int k) {
        if (start == end) return nums[start];
        int left = start + 1, right = end;
        while (left <= right) {
            while (nums[left] < nums[start] && left <= right) {
                left ++;
            }
            while (nums[right] >= nums[start] && left <= right) {
                right --;
            }
            if (left < right) {
                swap(nums[left], nums[right]);
                left ++;
                right --;
            }
        }
        swap(nums[right], nums[start]);
        if (right - start + 1 == k) return nums[right];
        else if (right - start + 1 < k) return findk(nums, right + 1, end, k - (right - start + 1));
        else return findk(nums, start, right - 1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        return findk(nums, 0, len - 1, len - k + 1);
    }
};