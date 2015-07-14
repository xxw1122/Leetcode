class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        vector<int> vis(26, 0);
        for (int i = 0; i < s1.size(); i ++) {
            vis[s1[i] - 'a'] ++;
        }
        for (int i = 0; i < s2.size(); i ++) {
            if (--vis[s2[i] - 'a'] < 0) return false;
        }
        int len = s1.size();
        if (len <= 3) return true;
        for (int i = 1; i < len; i ++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i, len - i), s2.substr(i, len - i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(len - i)) && 
                isScramble(s1.substr(i), s2.substr(0, len - i)))
                return true;
        }
        return false;
    }
};