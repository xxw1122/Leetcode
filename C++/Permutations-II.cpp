class Solution {
public:
    bool Next_Permutation(vector<int> &nums) {
        if (nums.empty() || nums.size() <= 1) return false;
        int pb = nums.size() - 1, pa = pb - 1, pc = pb;
        while (pa >= 0 && nums[pa] >= nums[pb]) {
            pb --;
            pa --;
        }
        if (pa < 0) return false;
        while (pc >= 0 && nums[pc] <= nums[pa]) {
            pc --;
        }
        swap(nums[pa], nums[pc]);
        int left = pb, right = nums.size() - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left ++;
            right --;
        }
        return true;
    }
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        res.push_back(nums);
        while (Next_Permutation(nums)) {
            res.push_back(nums);
        }
        return res;
    }
};