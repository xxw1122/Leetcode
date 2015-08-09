class Solution {
public:
    string shortestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int len = s.length();
        for (int i = len; i >= 0; i --) {
            if (s.substr(0, i) == s2.substr(len - i)) {
                return s2.substr(0, len - i) + s;
            }
        }
    }
};
