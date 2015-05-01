#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<int> vec(n);
        vec[0] = 1, vec[1] = 1, vec[2] = 0;
        for (int i = 2; i < n; i ++) {
            if (vec[i] == 0) {
                for (int j = i * 2; j < n; j += i) {
                    vec[j] = 1;
                }
            }
        }
        int num = 0;
        for (int i = 2; i < n; i ++) {
            if (vec[i] == 0) num ++;
        }
        return num;
    }
};