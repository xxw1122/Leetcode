#include <vector>

class Solution {
public:
    void solve (vector<vector<int> > &res, vector<int> &cnt, int pos, int num, int k, int n, int temp) {
        if (temp == n && pos <= 10 && num == k) res.push_back(cnt);
        if (pos > 9 || num >= k || temp >= n) return;
        cnt.push_back(pos);
        solve(res, cnt, pos + 1, num + 1, k, n, temp + pos);
        cnt.pop_back();
        solve(res, cnt, pos + 1, num, k, n, temp);
    }
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> cnt;
        solve(res, cnt, 1, 0, k, n, 0);
        return res;
    }
};