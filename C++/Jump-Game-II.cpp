class Solution {
public:
    int jump(vector<int>& nums) {
        int sc = 0, end = 0, maxsteps = 0;
        for (int i = 0; i < nums.size() - 1; i ++) {
            maxsteps = max(maxsteps, nums[i] + i);
            if (i == end) {
                end = maxsteps;
                sc++;
            }
        }
        return sc;
    }
};