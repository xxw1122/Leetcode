class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.empty()) return 0;
        int len = triangle.size();
        vector<int> res(len);
        for (int i = 0; i < len; i ++) {
            res[i] = triangle[len - 1][i];
        }
        for (int i = len - 2; i >= 0; i --) {
            for (int j = 0; j <= i; j ++) {
                res[j] = min(res[j], res[j + 1]) + triangle[i][j];
            }
        }
        return res[0];
    }
};