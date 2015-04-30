#include <vector>

class Solution {
public:
    void dfs(int x, int y, vector<vector<char> > &grid) {
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, 1, -1};
        grid[x][y] = '0';
        int x1, y1;
        for (int i = 0; i < 4; i ++) {
            x1 = x + dx[i];
            y1 = y + dy[i];
            if (x1 >= 0 && x1 < grid.size() && y1 >= 0 && y1 < grid[0].size() && grid[x1][y1] == '1') {
                dfs(x1, y1, grid);
            }
        }
    }
    int numIslands(vector<vector<char> > &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int len1 = grid.size(), len2 = grid[0].size(), num = 0;
        for (int i = 0; i < len1; i ++) {
            for (int j = 0; j < len2; j ++) {
                if (grid[i][j] == '1') {
                    num ++;
                    dfs(i, j, grid);
                }
            }
        }
        return num;
    }
};