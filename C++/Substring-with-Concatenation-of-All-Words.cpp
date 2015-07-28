class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        int lenw = words.size(), lens = s.size(), len = words[0].size();
        unordered_map<string, int> hash;
        for (int i = 0; i < lenw; i ++) {
        	if (hash.find(words[i]) != hash.end()) hash[words[i]] ++;
        	else hash.insert(make_pair(words[i], 1));
        }
        for (int i = 0; i + len * lenw - 1 < lens; i ++) {
        	unordered_map<string, int> cur(hash);
        	int sign = 1;
        	for (int j = i; j < i + len * lenw; j += len) {
        		string str = s.substr(j, len);
        		if (cur.find(str) == cur.end()) {
        			sign = 0;
        			break;
        		} else {
        			cur[str] --;
        			if (cur[str] == 0) {
        				cur.erase(str);
        			}
        		}
        	}
        	if (sign == 1 && cur.empty()) res.push_back(i);
        }
        return res;
    }
};