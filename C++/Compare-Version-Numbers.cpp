class Solution {
public:
    int compareVersion(string version1, string version2) {
        int num1 = 0, num2 = 0, len1 = version1.size(), len2 = version2.size();
        int p1 = 0, p2 = 0;
        while (p1 < len1 || p2 < len2) {
        	while (p1 < len1 && version1[p1] != '.') {
        		num1 = num1 * 10 + version1[p1 ++] - '0';
        	}
        	while (p2 < len2 && version2[p2] != '.') {
        		num2 = num2 * 10 + version2[p2 ++] - '0';
        	}
        	if (num1 > num2) return 1;
        	else if (num1 < num2) return -1;
        	num1 = 0;
        	num2 = 0;
        	p1 ++;
        	p2 ++;
        }
        return 0;
    }
};