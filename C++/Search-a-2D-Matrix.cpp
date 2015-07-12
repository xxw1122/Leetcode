class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int lenx = matrix.size(), leny = matrix[0].size();
        int left = 0, right = lenx * leny - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int x = mid / leny, y = mid % leny;
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};