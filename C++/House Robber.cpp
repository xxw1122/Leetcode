#include <vector>

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = nums.size();
        vector<int> vec(len + 1);
        vec[1] = nums[0];
        for (int i = 2; i <= len; i ++) {
            vec[i] = max(vec[i-1], vec[i-2] + nums[i-1]);
        }
        return vec[len];
    }
};