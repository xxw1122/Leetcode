class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minlen = nums.size() + 1, cur = 0, left = 0;
        for (int i = 0; i < nums.size(); i ++) {
            cur += nums[i];
            while (cur >= s) {
                minlen = min(minlen, i - left + 1);
                cur -= nums[left++];
            }
        }
        if (minlen > nums.size()) return 0;
        else return minlen;
    }
};