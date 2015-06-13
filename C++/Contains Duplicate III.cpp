#include <vector>
#include <set>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> hash;
        int len = nums.size();
        if (len <= 1 || t < 0) return false;
        if (k + 1 > len) k = len - 1;
        for (int i = 0; i <= k; i ++) {
            if (hash.find(nums[i]) != hash.end()) return true;
            hash.insert(nums[i]);
        }
        auto it = hash.begin();
        while (it != hash.end()) {
            auto it1 = it;
            it1 ++;
            if (it1 == hash.end()) break;
            if (*it1 - *it <= t) return true;
            it ++;
        }
        for (int i = k + 1; i < len; i ++) {
            hash.erase(nums[i-k-1]);
            if (hash.find(nums[i]) != hash.end()) return true;
            hash.insert(nums[i]);
            auto it2 = hash.find(nums[i]);
            auto it1 = it2, it3 = it2;
            if (it1 != hash.begin()) {
                it1 --;
                if (*it2 - *it1 <= t) return true;
            }
            it3 ++;
            if (it3 != hash.end()) {
                if (*it3 - *it2 <= t) return true;
            }
        }
        return false;
    }
};