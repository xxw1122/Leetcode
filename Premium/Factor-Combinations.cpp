class Solution {
public:
	void helper(vector<vector<int> >& res, vector<int> &cur, vector<int>& temp, int pos, int num) {
		if (num == 1 && !temp.empty()) {
			res.push_back(temp);
		}
		if (pos >= cur.size()) return;
		for (int i = pos; i < cur.size(); i ++) {
			if (num % cur[i] == 0) {
				temp.push_back(cur[i]);
				helper(res, cur, temp, i, num / cur[i]);
				temp.pop_back();
			}
		}
	}
    vector<vector<int> > getFactors(int n) {
        vector<int> cur;
        for (int i = 2; i < n; i ++) {
        	if (n % i == 0) {
        		cur.push_back(i);
        	}
        }
        vector<vector<int> > res;
        vector<int> temp;
        helper(res, cur, temp, 0, n);
        return res;
    }
};