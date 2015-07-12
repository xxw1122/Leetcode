class Solution {
public:
    void helper(vector<vector<int> >&res, vector<int> &cur, int n, int k, int index) {
        if (k == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = index; i <= n; i ++) {
            cur.push_back(i);
            helper(res, cur, n, k - 1, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<int> cur;
        vector<vector<int> > res;
        helper(res, cur, n, k, 1);
        return res;
    }
};