class Solution {
public:
	int convertInt(const string& str, map<char, int>& hash) {
		int res = 0;
		for (int i = 0; i < 10; i ++) {
			res = res * 4 + hash[str[i]];
		}
		return res;
	}
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        map<char, int> hash;
        map<int, int> vis;
        int size = 1 << 20;
        hash['A'] = 0, hash['C'] = 1, hash['G'] = 2, hash['T'] = 3;
        for (int i = 0; i + 9 < s.size(); i ++) {
        	string str = s.substr(i, 10);
        	int cur = convertInt(str, hash);
        	vis[cur] ++;
        	if (vis[cur] == 2) {
        		res.push_back(str);
        	}
        }
        return res;
    }
};