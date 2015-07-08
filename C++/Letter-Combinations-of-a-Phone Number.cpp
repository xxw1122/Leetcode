class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string dict[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.size() == 0) return res;
        res.push_back("");
        for (int i = 0; i < digits.size(); i ++) {
            if (digits[i] >= '2' && digits[i] <= '9') {
                vector<string> temp;
                for (int j = 0; j < res.size(); j ++) {
                    int index = digits[i] - '2';
                    for (int k = 0; k < dict[index].size(); k ++) {
                        string cur = res[j] + dict[index][k];
                        temp.push_back(cur);
                    }
                }
                swap(temp, res);
            }
        }
        return res;
    }
};