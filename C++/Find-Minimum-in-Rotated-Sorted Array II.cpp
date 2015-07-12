class Solution {
public:
    int findMin(vector<int> &num) {
        int minv = num[0];
        for (int i = 1; i < num.size(); i ++) {
            minv = min(minv, num[i]);
        }
        return minv;
    }
};