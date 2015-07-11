class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
        int lenx = obstacleGrid.size(), leny = obstacleGrid[0].size();
        vector<vector<int> > res(lenx, vector<int>(leny, 0));
        res[0][0] = 1;
        for (int i = 1; i < leny; i ++) {
            if (obstacleGrid[0][i] == 0 && res[0][i - 1] == 1) res[0][i] = 1;
        }
        for (int i = 1; i < lenx; i ++) {
            if (obstacleGrid[i][0] == 0 && res[i - 1][0] == 1) res[i][0] = 1;
        }
        for (int i = 1; i < lenx; i ++) {
            for (int j = 1; j < leny; j ++) {
                if (obstacleGrid[i][j] == 0) {
                    res[i][j] = res[i - 1][j] + res[i][j - 1];
                }
            }
        }
        return res[lenx - 1][leny - 1];
    }
};