class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size(); i ++) {
            if (hash.find(nums[i]) == hash.end()) {
                hash.insert(nums[i]);
            }
        }
        int maxlen = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (hash.find(nums[i]) == hash.end()) continue;
            int cur = 1, cnt = nums[i] - 1;
            hash.erase(nums[i]);
            while (hash.find(cnt) != hash.end()) {
                cur ++;
                hash.erase(cnt--);
            }
            cnt = nums[i] + 1;
            while (hash.find(cnt) != hash.end()) {
                cur ++;
                hash.erase(cnt++);
            }
            maxlen = max(maxlen, cur);
        }
        return maxlen;
    }
};