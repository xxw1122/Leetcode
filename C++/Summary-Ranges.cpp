class Solution {
public:
    string convert(int start, int end) {
        string str = to_string(start);
        str += "->";
        str += to_string(end);
        return str;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        int start = nums[0], end = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] == end + 1) {
                end ++;
            } else {
                if (end - start >= 1) {
                    res.push_back(convert(start, end));
                } else {
                    res.push_back(to_string(end));
                }
                start = end = nums[i];
            }
        }
        if (end - start >= 1) {                    
            res.push_back(convert(start, end));            
        } else {                    
            res.push_back(to_string(end));                
        }
        return res;
    }
};