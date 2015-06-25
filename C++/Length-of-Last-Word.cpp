class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0, cur = s.size() - 1;
        while (cur >= 0 && s[cur] == ' ') {
            cur --;
        }
        while (cur >= 0 && s[cur] != ' ') {
            cur --;
            res ++;
        }
        return res;
    }
};