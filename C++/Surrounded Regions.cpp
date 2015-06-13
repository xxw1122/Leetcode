#include <vector>
#include <queue>

class Solution {
public:
    void bfs(vector<vector<char> > &board, int x, int y) {
        int lenx = board.size(), leny = board[0].size();
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
        queue<pair<int, int> > que;
        board[x][y] = '1';
        que.push(make_pair(x, y));
        while (!que.empty()) {
            int x1 = que.front().first, y1 = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i ++) {
                int x2 = x1 + dx[i], y2 = y1 + dy[i];
                if (x2 >= 0 && x2 < lenx && y2 >= 0 && y2 < leny && board[x2][y2] == 'O') {
                    board[x2][y2] = '1';
                    que.push(make_pair(x2, y2));
                }
            }
        }
    }
    void solve(vector<vector<char> >& board) {
        if (board.empty() || board[0].empty()) return;
        int lenx = board.size(), leny = board[0].size();
        for (int i = 0; i < lenx; i ++) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][leny - 1] == 'O')  bfs(board, i, leny - 1);
        }
        for (int i = 0; i < leny; i ++) {
            if (board[0][i] == 'O') bfs(board, 0, i);
            if (board[lenx - 1][i] == 'O') bfs(board, lenx - 1, i);
        }
        for (int i = 0; i < lenx; i ++) {
            for (int j = 0; j < leny; j ++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for (int i = 0; i < lenx; i ++) {
            for (int j = 0; j < leny; j ++) {
                if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
};