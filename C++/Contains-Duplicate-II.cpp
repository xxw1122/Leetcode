class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty()) return false;
        //if (k == 0) return true;
        set<int> hash;
        for (int i = 0; i <= k && i < nums.size(); i ++) {
            if (hash.find(nums[i]) != hash.end()) return true;
            hash.insert(nums[i]);
        }
        for (int i = k + 1; i < nums.size(); i ++) {
            hash.erase(nums[i - k - 1]);
            if (hash.find(nums[i]) != hash.end()) return true;
            hash.insert(nums[i]);
        }
        return false;
    }
};