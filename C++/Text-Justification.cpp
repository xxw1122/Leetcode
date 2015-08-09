class Solution {
public:
    void helper(vector<string>& res, vector<string>& cur, int maxWidth, int temp) {
        if (cur.empty()) return;
        if (cur.size() == 1) {
            string str(maxWidth - cur[0].size(), ' ');
            res.push_back(cur[0] + str);
        } else {
            int spacenum = (maxWidth - temp) / (cur.size() - 1);
            int leftspace = (maxWidth - temp) % (cur.size() - 1);
            string str = "";
            for (int i = 0; i < leftspace; i ++) {
                str += cur[i];
                str += string(spacenum + 1, ' ');
            }
            for (int i = leftspace; i < cur.size() - 1; i ++) {
                str += cur[i];
                str += string(spacenum, ' ');
            }
            str += cur.back();
            res.push_back(str);
        }
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> cur, res;
        int temp = 0;
        for (int i = 0; i < words.size(); i ++) {
            if (cur.empty() || (temp + cur.size() + words[i].size() <= maxWidth)) {
                cur.push_back(words[i]);
                temp += words[i].size();
            } else {
                helper(res, cur, maxWidth, temp);
                cur.clear();
                cur.push_back(words[i]);
                temp = words[i].size();
            }
        }
        if (!cur.empty()) {
            string str = cur[0];
            for (int i = 1; i < cur.size(); i ++) {
                str += " ";
                str += cur[i];
            }
            str += string(maxWidth - temp - cur.size() + 1, ' ');
            res.push_back(str);
        }
        return res;
    }
};

