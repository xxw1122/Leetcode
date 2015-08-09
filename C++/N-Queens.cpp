class Solution {
public:
    void helper(vector<vector<string> >& res, vector<string>& cur, 
        vector<vector<int> >& vis, int pos, int n) {
        if (pos >= n) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < n; i ++) {
            if (vis[0][i] == 0 && vis[1][n + i - pos] == 0 && vis[2][i + pos] == 0) {
                vis[0][i] = vis[1][n + i - pos] = vis[2][i + pos] = 1;
                cur[pos][i] = 'Q';
                helper(res, cur, vis, pos + 1, n);
                cur[pos][i] = '.';
                vis[0][i] = vis[1][n + i - pos] = vis[2][i + pos] = 0;
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> cur;
        string str = "";
        for (int i = 0; i < n; i ++) {
            str += '.';
        }
        for (int i = 0; i < n; i ++) {
            cur.push_back(str);
        }
        vector<vector<int> > vis(3, vector<int>(30, 0));
        helper(res, cur, vis, 0, n);
        return res;
    }
};