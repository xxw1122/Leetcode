class Solution {
public:
    bool helper(vector<vector<char> >& board, vector<vector<int> >& row, vector<vector<int> >&col, 
        vector<vector<int> > &mat, int num) {
        if (num == 0) return true;
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') {
                    int x1 = i / 3, y1 = j / 3;
                    int temp = x1 * 3 + y1;
                    for (int k = 0; k < 9; k ++) {
                        if (row[i][k] == 0 && col[j][k] == 0 && mat[temp][k] == 0) {
                            row[i][k] = col[j][k] = mat[temp][k] = 1;
                            board[i][j] = ('1' + k);
                            if (helper(board, row, col, mat, num - 1)) return true;
                            row[i][k] = col[j][k] = mat[temp][k] = 0;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char> >& board) {
        vector<vector<int> > row(9, vector<int>(9, 0));
        vector<vector<int> > col(9, vector<int>(9, 0));
        vector<vector<int> > mat(9, vector<int>(9, 0));
        int num = 0;
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    num ++;
                    int digit = board[i][j] - '1';
                    row[i][digit] ++;
                    col[j][digit] ++;
                    int x = i / 3, y = j / 3;
                    mat[x * 3 + y][digit] ++;
                }
            }
        }
        num = 81 - num;
        helper(board, row, col, mat, num);
    }
};