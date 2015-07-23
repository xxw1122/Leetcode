class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur(1, 1);
        for (int i = 1; i <= rowIndex; i ++) {
            vector<int> temp(i + 1);
            for (int j = 0; j <= i; j ++) {
                int left, right;
                if (j - 1 < 0) left = 0;
                else left = cur[j - 1];
                if (j >= i) right = 0;
                else right = cur[j];
                temp[j] = left + right;
            }
            swap(temp, cur);
        }
        return cur;
    }
};