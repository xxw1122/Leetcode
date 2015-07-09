class Solution {
public:
    int findLeft(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (nums[left] == target) return left;
        else if (nums[right] == target) return right;
        else return -1;
    }
    int findRight(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (nums[right] == target) return left;
        else if (nums[left] == target) return right;
        else return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(findLeft(nums, target));
        res.push_back(findRight(nums, target));
        return res;
    }
};