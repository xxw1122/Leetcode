#include <vector>

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int ret = 0, last = 0, curr = 0;
        for (int i = 0; i < A.size(); i ++) {
            if (i > last) {
                last = curr;
                ret ++;
            }
            curr = max(curr, i + A[i]);
        }
        return ret;
    }
};
