class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        if (strs.empty()) return str;
        for (int i = 0; i < strs[0].size(); i ++) {
        	for (int j = 0; j < strs.size(); j ++) {
        		if (i >= strs[j].size() || strs[j][i] != strs[0][i]) return str;
        	}
        	str += strs[0][i];
        }
        return str;
    }
};