class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<int> vis(n);
        vis[0] = 1, vis[1] = 1; vis[2] = 0;
        for (int i = 2; i < n; i ++) {
            if (vis[i] == 0) {
                for (int j = i * 2; j < n; j += i) {
                    vis[j] = 1;
                }
            }
        }
        int num = 0;
        for (int i = 2; i < n; i ++) {
            if (vis[i] == 0) num ++;
        }
        return num;
    }
};