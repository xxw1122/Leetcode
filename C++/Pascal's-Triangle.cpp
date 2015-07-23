class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows <= 0) return res;
        vector<int> cur(1, 1);
        res.push_back(cur);
        for (int i = 1; i < numRows; i ++) {
        	vector<int> temp(i + 1);
        	for (int j = 0; j <= i; j ++) {
        		int left, right;
        		if (j - 1 < 0) left = 0;
        		else left = cur[j - 1];
        		if (j >= i) right = 0;
        		else right = cur[j];
        		temp[j] = left + right;
        	}
        	res.push_back(temp);
        	swap(temp, cur);
        }
        return res;
    }
};