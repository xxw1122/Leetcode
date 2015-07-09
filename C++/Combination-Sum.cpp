class Solution {
public:
    void helper(vector<int> &candidates, int target, int index, vector<vector<int> > &res, vector<int> &cur) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = index; i < candidates.size(); i ++) {
            if (candidates[i] > target) break;
            cur.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i, res, cur);
            cur.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        helper(candidates, target, 0, res, cur);
        return res;
    }
};