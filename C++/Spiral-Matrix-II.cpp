class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int cur = 0, x = 0, y = 0;
        int left = 0, right = n - 1, up = 0, down = n - 1;
        while (cur < n * n) {
        	while (cur < n * n && y <= right && matrix[x][y] == 0) {
        		matrix[x][y ++] = ++ cur;
        	}
        	y --, up ++, x ++;
        	while (cur < n * n && x <= down && matrix[x][y] == 0) {
        		matrix[x ++][y] = ++ cur;
        	}
        	x --, y --, right --;
        	while (cur < n * n && y >= 0 && matrix[x][y] == 0) {
        		matrix[x][y --] = ++ cur;
        	}
        	y ++, x --, down --;
        	while (cur < n * n && x >= 0 && matrix[x][y] == 0) {
        		matrix[x --][y] = ++ cur;
        	}
        	x ++, y ++, left ++;
        }
        return matrix;
    }
};