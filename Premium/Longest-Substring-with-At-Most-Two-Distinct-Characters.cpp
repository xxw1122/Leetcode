class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int hash[256];
        memset(hash, 0, sizeof(hash));
        int cur = 0, maxlen = 0, start = 0;
        for (int i = 0; i < s.size(); i ++) {
        	if ( ++ hash[s[i]] == 1) cur ++;
        	while (cur > 2) {
        		if (-- hash[s[start ++]] == 0) {
        			cur --;
        		}
        	}
        	maxlen = max(maxlen, i - start + 1);
        }
        return maxlen;
    }
};