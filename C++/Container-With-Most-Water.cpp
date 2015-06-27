class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            res = max(min(height[left], height[right]) * (right - left), res);
            if (height[left] <= height[right]) {
                left ++;
            } else {
                right --;
            }
        }
        return res; 
    }
};