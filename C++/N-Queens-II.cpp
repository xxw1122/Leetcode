class Solution {
public:
	void helper(vector<vector<int> >& vis, int pos, int n, int& res) {
        if (pos >= n) {
            res ++;
            return;
        }
        for (int i = 0; i < n; i ++) {
            if (vis[0][i] == 0 && vis[1][n + i - pos] == 0 && vis[2][i + pos] == 0) {
                vis[0][i] = vis[1][n + i - pos] = vis[2][i + pos] = 1;                
                helper(vis, pos + 1, n, res);
                vis[0][i] = vis[1][n + i - pos] = vis[2][i + pos] = 0;
            }
        }
    }
    int totalNQueens(int n) {
    	int res = 0;
        vector<vector<int> > vis(3, vector<int>(30, 0));
        helper(vis, 0, n, res);
        return res;
    }
};