class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        height.push_back(0);
        stack<int> stk;
        int i = 0;
        int maxArea = 0;
        while (i < height.size()) {
            if (stk.empty() || height[stk.top()] <= height[i]) {
                stk.push(i++);
            } else {
                int t = stk.top();
                stk.pop();
                maxArea = max(maxArea, height[t] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }
        return maxArea;
    }
};

