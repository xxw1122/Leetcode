class Solution {
public:
    bool HasNext(vector<int> &nums) {
        if (nums.empty() || nums.size() <= 1) return false;
        int pb = nums.size() - 1, pa = pb - 1;
        while (pa >= 0 && nums[pa] >= nums[pb]) {
            pa --;
            pb --;
        }
        if (pa < 0) return false;
        int pc = nums.size() - 1;
        while (pc >= 0 && nums[pa] >= nums[pc]) {
            pc --;
        }
        swap(nums[pc], nums[pa]);
        int left = pb, right = nums.size() - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left ++;
            right --;
        }
    }
    void nextPermutation(vector<int>& nums) {
        if (HasNext(nums)) return;
        reverse(nums.begin(), nums.end());
    }
};