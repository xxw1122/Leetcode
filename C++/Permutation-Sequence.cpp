#include <string>
#include <vector>

class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    int factor(int x) {
        int res = 1;
        for (int i = 2; i <= x; i ++) {
            res *= i;
        }
        return res;
    }
    int get(vector<int> &vis, int pos) {
        int cnt = 0;
        for (int i = 0; i < vis.size(); i ++) {
            if (pos == cnt && vis[i] == 0) return i + 1;
            else if (vis[i] == 0) cnt ++;
        }
    }
    string getPermutation(int n, int k) {
        vector<int> vis(n);
        string s;
        int num = 0;
        while (num < n) {
            int cnt = factor(n - num - 1);
            int res = k / cnt;
            if (res != 0 && k % cnt == 0) {
                res --;
            }
            k -= res * cnt;
            int ans = get(vis, res);
            char ch = '0' + ans;
            s += ch;
            vis[ans-1] = 1;
            num += 1;
        }
        return s;
    }
};
