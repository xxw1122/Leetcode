class Solution {
public:
    int strStr(string haystack, string needle) {
    	int len1 = haystack.size(), len2 = needle.size();
        for (int i = 0; i + len2 - 1 < len1; i ++) {
        	int j = 0;
        	for (j = 0; j < len2; j ++) {
        		if (needle[j] != haystack[i + j]) break;
        	}
        	if (j == len2) return i;
        }
        return -1;
    }
};