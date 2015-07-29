class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;
        vector<int> catalan(n + 1);
        catalan[0] = catalan[1] = 1;
        for (int i = 2; i <= n; i ++) {
            int cur = 0;
            for (int j = 0; j < i; j ++) {
                cur += catalan[j] * catalan[i - 1 - j];
            }
            catalan[i] = cur;
        }
        return catalan[n];
    }
};