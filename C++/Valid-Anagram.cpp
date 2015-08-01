class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s.size() != t.size()) return false;
        vector<int> vis(26, 0);
        for (int i = 0; i < s.size(); i ++) {
        	vis[s[i] - 'a'] ++;
        }
        for (int i = 0; i < t.size(); i ++) {
        	if (-- vis[t[i]- 'a'] < 0) return false;
        }
        for (int i = 0; i < 26; i ++) {
        	if (vis[i] != 0) return false;
        }
        return true;
    }
};