class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > res(m, vector<int>(n, 1));
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        }
        return res[m - 1][n - 1];
    }
};