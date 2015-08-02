class Solution {
public:
    void helper(vector<vector<int> >& res, vector<int> &cur, int k, int n, int pos) {
        if (k == 0 && n == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = pos; i <= 9; i ++) {
            if (i > n) return;
            cur.push_back(i);
            helper(res, cur, k - 1, n - i, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> cur;
        helper(res, cur, k, n, 1);
        return res;
    }
};