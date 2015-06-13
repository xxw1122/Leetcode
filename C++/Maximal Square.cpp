#include <vector>

/*
  O(N^2)
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        vector<vector<int> > size(m, vector<int>(n, 0));
        int maxsize = 0;
        for (int j = 0; j < n; j++) {
            size[0][j] = matrix[0][j] - '0';
            maxsize = max(maxsize, size[0][j]);
        }
        for (int i = 1; i < m; i++) {
            size[i][0] = matrix[i][0] - '0';
            maxsize = max(maxsize, size[i][0]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    size[i][j] = min(size[i - 1][j - 1], min(size[i - 1][j], size[i][j - 1])) + 1;
                    maxsize = max(maxsize, size[i][j]);
                }
            }
        }
        return maxsize * maxsize;
    }
};