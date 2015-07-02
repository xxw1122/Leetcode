class Solution {
public:
    int myAtoi(string str) {
        int cur = 0, i = 0, sign = 1;
        while (str[i] == ' ') i ++;
        if (str[i] == '-') {
        	sign = -1;
        	i ++;
        } else if (str[i] == '+') {
        	i ++;
        } else if (str[i] < '0' && str[i] > '9') {
        	return 0;
        }
        for (; i < str.size(); i ++) {
        	if (str[i] < '0' || str[i] > '9') break;
        	if (sign == 1 && ((cur > INT_MAX / 10) || (cur == INT_MAX / 10 && str[i] >= '7'))) return INT_MAX;
        	else if(sign == -1 && ((cur > INT_MAX / 10) || (cur == INT_MAX / 10 && str[i] >= '8'))) return INT_MIN;
       		cur = cur * 10 + str[i] - '0';
        }
        return cur * sign;
    }
};