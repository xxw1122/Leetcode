class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> cur;
        string str = "";
        for (int i = 0; i < n; i ++) {
            str += '.';
        }
        for (int i = 0; i < n; i ++) {
            cur.push_back(str);
        }
    }
};