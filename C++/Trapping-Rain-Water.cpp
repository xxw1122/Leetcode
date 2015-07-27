class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int maxh = -1, maxp = -1;
        for (int i = 0; i < height.size(); i ++) {
            if (height[i] > maxh) {
                maxh = height[i];
                maxp = i;
            }
        }
        int leftm = height[0], rightm = height[height.size() - 1], res = 0;
        for (int i = 1; i < maxp; i ++) {
            if (height[i] < leftm) res += (leftm - height[i]);
            else leftm = height[i];
        }
        for (int i = height.size() - 1; i > maxp; i --) {
            if (height[i] < rightm) res += (rightm - height[i]);
            else rightm = height[i];
        }
        return res;
    }
};