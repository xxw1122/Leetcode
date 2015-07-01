class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<vector<char> > res(numRows);
        int cur = 0, index = 0, len = s.size();
        while (index < len) {
            while (cur + 1 < numRows && index < len) {
                res[cur ++].push_back(s[index ++]);
            }
            while (cur > 0 && index < len) {
                res[cur --].push_back(s[index ++]);
            }
        }
        string str;
        for (int i = 0; i < numRows; i ++) {
            for (int j = 0; j < res[i].size(); j ++) {
                str += res[i][j];
            }
        }
        return str;
    }
};