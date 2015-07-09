class Solution {
public:
    void helper(vector<int> &candidates, int target, int index, vector<vector<int> > &res, vector<int> &cur) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        int prev = -1, tag = -1;
        for (int i = index; i < candidates.size(); i ++) {
            if (candidates[i] > target) break;
            if (tag == 1 && candidates[i] == prev) continue;
            tag = 1;
            prev = candidates[i];
            cur.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i + 1, res, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        helper(candidates, target, 0, res, cur);
        return res;
    }
};