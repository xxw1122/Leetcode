class Solution {
public:
    string multiply(string num1, string num2) {
    	if (num1 == "0" || num2 == "0") return "0";
        int len1 = num1.size(), len2 = num2.size();
        vector<int> res(len1 + len2, 0);
        for (int i = 0; i < len1; i ++) {
        	for (int j = 0; j < len2; j ++) {
        		res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        	}
        }
        for (int i = 0; i < len1 + len2; i ++) {
        	int j = len1 + len2 - i - 1;
        	if (res[j] >= 10) {
        		res[j - 1] += res[j] / 10;
        		res[j] = res[j] % 10;
        	}
        }
        int cur = 0;
        while (cur < len1 + len2 && res[cur] == 0) {
        	cur ++;
        }
        string str = "";
        for (int i = cur; i < len1 + len2; i ++) {
        	char ch = res[i] + '0';
        	str += ch;
        }
        return str;
    }
};