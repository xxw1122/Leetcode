class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = nums.size();
        if (len == 1) return nums[0];
        vector<int> vec1(len + 1), vec2(len + 1);
        vec1[1] = nums[0], vec2[2] = nums[1];
        for (int i = 2; i <= len-1; i ++) {
            vec1[i] = max(vec1[i-1], vec1[i-2] + nums[i-1]);
        }
        for (int i = 3; i <= len; i ++) {
            vec2[i] = max(vec2[i-1], vec2[i-2] + nums[i-1]);
        }
        return max(vec1[len-1], vec2[len]);
    }
};