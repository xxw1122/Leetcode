class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int lenx = grid.size(), leny = grid[0].size();
        vector<vector<int> > res(lenx, vector<int>(leny));
        res[0][0] = grid[0][0];
        for (int i = 1; i < lenx; i ++) {
            res[i][0] = grid[i][0] + res[i - 1][0];
        }
        for (int i = 1; i < leny; i ++) {
            res[0][i] = grid[0][i] + res[0][i - 1];
        }
        for (int i = 1; i < lenx; i ++) {
            for (int j = 1; j < leny; j ++) {
                res[i][j] = min(res[i - 1][j], res[i][j - 1]) + grid[i][j];
            }
        }
        return res[lenx - 1][leny - 1];
    }
};