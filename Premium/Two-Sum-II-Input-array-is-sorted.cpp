class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> res;
        while (left < right) {
        	int cur = numbers[left] + numbers[right];
        	if (cur == target) {
        		res.push_back(left + 1);
        		res.push_back(right + 1);
        		return res;
        	} else if (cur > target) {
        		right --;
        	} else {
        		left ++;
        	}
        }
        return res;
    }
};