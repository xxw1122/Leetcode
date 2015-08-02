class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        vector<vector<int> > row(9, vector<int>(9, 0));
        vector<vector<int> > col(9, vector<int>(9, 0));
        vector<vector<int> > mat(9, vector<int>(9, 0));
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '1';
                    row[i][digit] ++;
                    col[j][digit] ++;
                    int x = i / 3, y = j / 3;
                    mat[x * 3 + y][digit]  ++;
                }
            }
        }
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (row[i][j] > 1 || col[i][j] > 1 || mat[i][j] > 1) return false;
            }
        }
        return true;
    }
};