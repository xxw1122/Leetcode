class Solution {
public:
    bool CanReach(vector<vector<int> >&dungeon, int val) {
        int lenx = dungeon.size(), leny = dungeon[0].size();
        vector<vector<int> > vec(lenx, vector<int>(leny, -1));
        vec[0][0] = val + dungeon[0][0];
        if (vec[0][0] <= 0) return false;
        for (int i = 1; i < leny; i ++) {
            if (vec[0][i - 1] <= 0) break;
            vec[0][i] = vec[0][i - 1] + dungeon[0][i];
        }
        for (int i = 1; i < lenx; i ++) {
            if (vec[i - 1][0] <= 0) break;
            vec[i][0] = vec[i - 1][0] + dungeon[i][0];
        }
        for (int i = 1; i < lenx; i ++) {
            for (int j = 1; j < leny; j ++) {
                if (vec[i - 1][j] > 0) vec[i][j] = max(vec[i][j], vec[i - 1][j] + dungeon[i][j]);
                if (vec[i][j - 1] > 0) vec[i][j] = max(vec[i][j], vec[i][j - 1] + dungeon[i][j]);
            }
        }
        if (vec[lenx - 1][leny - 1] > 0) return true;
        return false;
    }
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int left = 1, right = INT_MAX, minval = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (CanReach(dungeon, mid)) {
                minval = min(minval, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return minval;
    }
};