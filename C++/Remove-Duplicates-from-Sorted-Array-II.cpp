class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = -1, time = 0, index = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (time == 0 || nums[i] != cur) {
                time = 1;
                cur = nums[i];
                nums[index ++] = nums[i];
            } else if (nums[i] == cur) {
                time ++;
                if (time <= 2) {
                    nums[index ++] = nums[i];
                }
            }
        }
        return index;
    }
};