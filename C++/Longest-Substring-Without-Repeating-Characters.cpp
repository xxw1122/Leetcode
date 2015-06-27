class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int left = 0, len = 0;
        vector<int> vis(256, 0);
        for (int i = 0; i < s.size(); i ++) {
            if (vis[s[i]] > 0) {
                while (vis[s[i]] > 0) {
                    vis[s[left]] --;
                    left ++;
                }
            }
            len = max(i - left + 1, len);
            vis[s[i]] ++;
        }
        return len;
    }
};