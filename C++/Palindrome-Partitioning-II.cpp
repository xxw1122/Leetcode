class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int len = s.size();
        vector<vector<int> > sign(len, vector<int>(len, 0));
        for (int i = 1; i <= len; i ++) {
            for (int j = 0; j + i - 1 < len; j ++) {
                if (i == 1) sign[j][j] = 1;
                else {
                    int k = j + i - 1;
                    if ((j + 1 >= k - 1 || sign[j + 1][k - 1] == 1) && s[j] == s[k]) {
                        sign[j][k] = 1;
                    }
                }
            }
        }
        vector<int> minc(len, 0);
        for (int i = 1; i < len; i ++) {
            minc[i] = i;
            if (sign[0][i] == 1) minc[i] = 0;
            for (int j = 0; j < i; j ++) {
                if (sign[j + 1][i] == 1) minc[i] = min(minc[i], minc[j] + 1);
            }
        }
        return minc[len - 1];
    }
};