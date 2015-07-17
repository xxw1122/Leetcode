class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int lenx = matrix.size(), leny = matrix[0].size();
        int x = 0, y = 0, num = lenx * leny, uppos = 0, leftpos = 0;
        while (res.size() < num) {
            while (y < leny) {
                res.push_back(matrix[x][y++]);
            }
            y --, x ++, uppos ++;
            while (x < lenx && res.size() < num) {
                res.push_back(matrix[x++][y]);
            }
            x --, y --, leny --;
            while (y >= leftpos && res.size() < num) {
                res.push_back(matrix[x][y--]);
            }
            y ++, x --, lenx --;
            while (x >= uppos && res.size() < num) {
                res.push_back(matrix[x--][y]);
            }
            x ++, y ++, leftpos ++;
        }
        return res;
    }
};