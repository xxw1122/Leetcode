class Solution {
public:
	void helper(vector<string>& res, map<char, char>& hash, string& str, int left, int right) {
		if (left > right) {
			res.push_back(str);
			return;
		}
		for (auto it = hash.begin(); it != hash.end(); it ++) {
			if (left == right) {
				if (it->first == it->second) {
					str[left] = it->first;
					res.push_back(str);
				}
			} else {
				if (left == 0 && it->first == '0') continue;
				str[left] = it->first;
				str[right] = it->second;
				helper(res, hash, str, left + 1, right - 1);
			}
		}
	}
    vector<string> findStrobogrammatic(int n) {
    	vector<string> res;
    	string str(n, '1');
    	map<char, char> hash;
        hash['0'] = '0';
        hash['1'] = '1';
        hash['6'] = '9';
        hash['8'] = '8';
        hash['9'] = '6';
        helper(res, hash, str, 0, n - 1);
        return res;
    }
};