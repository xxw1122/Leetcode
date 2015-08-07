class Solution {
public:
	bool Is_group(string &str1, string &str2) {
		if (str1 == str2) return true;
		if (str1.size() != str2.size()) return false;
		int offset = (str2[0] - str1[0] + 26) % 26;
		for (int i = 1; i < str1.size(); i ++) {
			char temp = (str1[i] - 'a' + offset) % 26 + 'a';
			if (temp != str2[i]) return false;
		}
		return true;
	}
    vector<vector<string> > groupStrings(vector<string>& strings) {
    	sort(strings.begin(), strings.end());
        vector<vector<string> > res;
        for (int i = 0; i < strings.size(); i ++) {
        	int flag = 0;
        	for (int j = 0; j < res.size(); j ++) {
        		if (Is_group(strings[i], res[j][0])) {
        			res[j].push_back(strings[i]);
        			flag = 1;
        			break;
        		}
        	}
        	if (flag == 0) {
        		vector<string> cur;
        		cur.push_back(strings[i]);
        		res.push_back(cur);
        	}
        }
        return res;
    }
};