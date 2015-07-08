class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 3 < nums.size(); i ++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j + 2 < nums.size(); j ++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int temp = nums[i] + nums[j] + nums[left] + nums[right];
                    if (temp == target) {
                        res.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        int temp1 = nums[left++], temp2 = nums[right--];
                        while (left < right && nums[left] == temp1) left++;
                        while (left < right && nums[right] == temp2) right--;
                    } else if (temp < target) {
                        left ++;
                    } else {
                        right --;
                    }
                }
            }
        }
        return res;
    }
};