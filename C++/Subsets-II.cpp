class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int> >& res, vector<int> &cur,int index) {
        res.push_back(cur);
        int cnt = -1, pre = -1;
        for (int i = index; i < nums.size(); i ++) {
            if (cnt == 1 && nums[i] == pre) continue;
            cnt = 1, pre = nums[i];
            cur.push_back(nums[i]);
            helper(nums, res, cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        vector<int> cur;
        helper(nums, res, cur, 0);
        return res;
    }
};