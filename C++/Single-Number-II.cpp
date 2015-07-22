class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0, cur = 1;
        for (int i = 0; i < 32; i ++) {
            cur = 1 << i;
            int num = 0;
            for (int j = 0; j < nums.size(); j ++) {
                if (nums[j] & cur) num ++;
            }
            if (num % 3 == 1) res = res | cur;
        }
        return res;
    }
};