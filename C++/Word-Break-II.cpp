class Solution {
public:
	string draw(vector<string> cur) {
		if (cur.empty()) return "";
		reverse(cur.begin(), cur.end());
		int len = cur.size();
		string str = cur[0];
		for (int i = 1; i < len; i ++) {
			str += ' ';
			str += cur[i];
		}
		return str;
	}
	void helper(vector<string>& res, vector<string>& cur, unordered_set<string>& wordDict,
		vector<bool>& Canbreak, string& s, int pos) {
		if (pos < 0) {
			res.push_back(draw(cur));
			return;
		}
		for (int i = pos; i >= 0; i --) {
			if (Canbreak[i] && wordDict.find(s.substr(i, pos - i + 1)) != wordDict.end()) {
				cur.push_back(s.substr(i, pos - i + 1));
				helper(res, cur, wordDict, Canbreak, s, i - 1);
				cur.pop_back();
			}
		}
	}
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    	int len = s.size();
    	vector<bool> Canbreak(len + 1, false);
    	Canbreak[0] = true;
    	for (int i = 1; i <= len; i ++) {
    		for (int j = 0; j < i; j ++) {
    			if (Canbreak[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
    				Canbreak[i] = true;
    				break;
    			}
    		}
    	}
    	vector<string> res, cur;
    	if (!Canbreak[len]) return res;
    	helper(res, cur, wordDict, Canbreak, s, len - 1);
    	return res;
    }
};