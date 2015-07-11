class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        if (matrix.empty() || matrix[0].empty()) return
        int lenx = matrix.size(), leny = matrix[0].size();
        for (int i = 0; i < lenx / 2; i ++) {
            for (int j = 0; j < leny; j ++) {
                swap(matrix[i][j], matrix[lenx - 1 - i][j]);
            }
        }
        for (int i = 0; i < lenx; i ++) {
            for (int j = i + 1; j < leny; j ++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};