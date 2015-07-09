class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int cur = 0;
        while (cur < nums.size()) {
            while (nums[cur] != cur + 1) {
                if (nums[cur] > nums.size() || nums[cur] <= 0) {
                    break;
                } else {
                    if (nums[nums[cur] - 1] == nums[cur]) break;
                    swap(nums[cur], nums[nums[cur] - 1]);
                }
            }
            cur ++;
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};