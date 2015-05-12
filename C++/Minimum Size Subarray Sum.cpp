#include <vector>

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minlen = nums.size(), len = nums.size(), start = 0, sum = 0, tag = 0;
        for (int i = 0; i < len; i ++) {
            sum += nums[i];
            while (sum >= s) {
                tag = 1;
                minlen = min(minlen, i - start + 1);
                sum -= nums[start];
                start ++;
            }
        }
        if (!tag) return 0;
        return minlen;
    }
};