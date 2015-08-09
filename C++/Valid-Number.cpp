class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // Write your code here
        int len = s.size();
        int i = 0, e = len - 1;
        while (i <= e && s[i] == ' ') i ++;
        if (i >= len) return false;
        while (i <= e && s[e] == ' ') e --;
        if (s[i] == '-' || s[i] == '+') i ++;
        bool num = false; // is a digit
        bool dot = false; // is a '.'
        bool expd = false; // is a 'e'
        while (i <= e) {
        	char c = s[i];
        	if (c >= '0' && c <= '9') {
        		num = true;
        	} else if (c == '.') {
        		if(expd || dot) return false;
                dot = true;
        	} else if (c == 'e') {
                if(expd || num == false) return false;
                expd = true;
                num = false;
            } else if (c == '+' || c == '-') {
            	if (s[i - 1] != 'e') return false;
            } else {
            	return false;
            }
            i ++;
        }
        return num;
    }
};
