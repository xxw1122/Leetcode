#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
        if (matrix.empty()) return;
        int len1 = matrix.size(), len2 = matrix[0].size();
        for (int i = 0; i < len1; i ++) {
            for (int j = 0; j < i; j ++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < len1; i ++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

