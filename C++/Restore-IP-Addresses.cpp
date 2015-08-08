class Solution {
public:
    void helper(vector<string>& res, vector<string> &cur, string &s, int pos) {
        if (pos == s.size() && cur.size() == 4) {
            string str = "";
            str += cur[0];
            for (int i = 1; i < 4; i ++) {
                str += ".";
                str += cur[i];
            }
            res.push_back(str);
            return;
        }
        if (cur.size() == 4 || pos >= s.size()) return;
        int temp = 0;
        for (int i = pos; i < s.size(); i ++) {
            temp = temp * 10 + s[i] - '0';
            if (temp > 255) break;
            if (s[pos] == '0' && i > pos) continue;
            cur.push_back(s.substr(pos, i - pos + 1));
            helper(res, cur, s, i + 1);
            cur.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> cur;
        helper(res, cur, s, 0);
        return res;
    }
};