class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int zerox = 0, zeroy = 0, lenx = matrix.size(), leny = matrix[0].size();
        for (int i = 0; i < leny; i ++) {
            if (matrix[0][i] == 0) {
                zerox = 1;
                break;
            }
        }
        for (int i = 0; i < lenx; i ++) {
            if (matrix[i][0] == 0) {
                zeroy = 1;
                break;
            }
        }
        for (int i = 0; i < lenx; i ++) {
            for (int j = 0; j < leny; j ++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < lenx; i ++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < leny; j ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < leny; i ++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < lenx; j ++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (zerox == 1) {
            for (int i = 0; i < leny; i ++) matrix[0][i] = 0;
        }
        if (zeroy == 1) {
            for (int i = 0; i < lenx; i ++) matrix[i][0] = 0;
        }
    }
};