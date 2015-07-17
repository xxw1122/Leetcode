class Solution {
public:
	bool helper(vector<vector<char> > &board, string &word, vector<vector<int> >& vis, int x, int y, int pos) {
		if (pos == word.size()) return true;
		int dx[4] = {1, -1, 0, 0};
	    int dy[4] = {0, 0, 1, -1};
		for (int i = 0; i < 4; i ++) {
			int x1 = dx[i] + x, y1 = dy[i] + y;
			if (x1 >= 0 && x1 < board.size() && y1 >= 0 && y1 < board[0].size() 
				&& board[x1][y1] == word[pos] && vis[x1][y1] == 0) {
				if (pos == word.size() - 1) return true;
				vis[x1][y1] = 1;
				if (helper(board, word, vis, x1, y1, pos + 1)) return true;
				vis[x1][y1] = 0;
			}
		}
		return false;
	}
    bool exist(vector<vector<char> >& board, string word) {
    	if (board.empty()) return false;
        int lenx = board.size(), leny = board[0].size();;
        vector<vector<int> > vis(lenx, vector<int>(leny, 0));
        for (int i = 0; i < board.size(); i ++) {
        	for (int j = 0; j < board[0].size(); j ++) {
        		if (board[i][j] != word[0]) continue;
        		vis[i][j] = 1;
        		if (helper(board, word, vis, i, j, 1)) return true;
        		vis[i][j] = 0;
        	}
        }
        return false;
    }
};