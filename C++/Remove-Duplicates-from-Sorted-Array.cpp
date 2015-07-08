class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = -1;
        for (int i = 0; i < nums.size(); i ++) {
            if (cur == -1 || nums[i] != nums[cur]) {
                nums[++cur] = nums[i];
            }
        }
        return cur + 1;
    }
};