class Solution {
public:
    void helper(vector<vector<string> >& res, vector<vector<int> >& sign, vector<string>& cur, int pos, string &s) {
        if (pos == s.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = pos; i < s.size(); i ++) {
            if (sign[pos][i] == 1) {
                cur.push_back(s.substr(pos, i - pos + 1));
                helper(res, sign, cur, i + 1, s);
                cur.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        if (s.empty()) return res;
        int len = s.size();
        vector<vector<int> > sign(len, vector<int>(len, 0));
        for (int i = 1; i <= len; i ++) {
            for (int j = 0; j + i - 1 < len; j ++) {
                if (i == 1) sign[j][j] = 1;
                else {
                    int k = j + i - 1;
                    if ((j + 1 >= k - 1 || sign[j + 1][k - 1] == 1) && s[j] == s[k]) {
                        sign[j][k] = 1;
                    }
                }
            }
        }
        vector<string> cur;
        helper(res, sign, cur, 0, s);
        return res;
    }
};