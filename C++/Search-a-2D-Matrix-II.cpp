class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.empty()) return false;
        int lenx = matrix.size(), leny = matrix[0].size();
        int x = 0, y = leny - 1;
        while (x < lenx && y >= 0) {
        	if (matrix[x][y] == target) return true;
        	else if (matrix[x][y] > target) y --;
        	else x ++;
        }
        return false;
    }
};