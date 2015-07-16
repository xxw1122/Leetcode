class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "" || s == "") return "";
        int left = 0, right = 0, maxlen = INT_MAX, pos = 0, num = 0, cur = 0;
        int Hash_T[256], Hash_S[256];
        memset(Hash_S, 0, sizeof(Hash_S));
        memset(Hash_T, 0, sizeof(Hash_T));
        for (int i = 0; i < t.size(); i ++) {
        	if (Hash_T[t[i]]++ == 0) num ++;
        }
        for (int i = 0; i < s.size(); i ++) {
        	if (++Hash_S[s[i]] == Hash_T[s[i]]) cur ++;
        	while (cur >= num) {
        		if (i - pos + 1 < maxlen) {
        			maxlen = i - pos + 1;
        			left = pos;
        		}
        		char ch = s[pos++];
        		if (Hash_S[ch] == Hash_T[ch]) {
        			cur --;
        		}
        		-- Hash_S[ch];
        	}
        }
        if (maxlen == INT_MAX) return "";
        return s.substr(left, maxlen);
    }
};