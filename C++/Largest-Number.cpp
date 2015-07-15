class Solution {
public:
	static bool cmp(string str1, string str2) {
		return str1 + str2 > str2 + str1;
	}
    string largestNumber(vector<int>& nums) {
        vector<string> res;
        for (int i = 0; i < nums.size(); i ++) {
        	res.push_back(to_string(nums[i]));
        }
        sort(res.begin(), res.end(), cmp);
        string str;
        for(int i = 0; i < nums.size(); i ++) {
        	str += res[i];
        }
        int index = 0;
        while (index < str.size() && str[index] == '0') index ++;
        if (index == str.size()) return "0";
        return str.substr(index);
    }
};