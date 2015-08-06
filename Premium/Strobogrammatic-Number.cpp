class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char, char> hash;
        hash['0'] = '0';
        hash['1'] = '1';
        hash['6'] = '9';
        hash['8'] = '8';
        hash['9'] = '6';
        int left = 0, right = num.size() - 1;
        while (left <= right) {
        	if (hash.find(num[left]) == hash.end() || hash.find(num[right]) == hash.end() || hash[num[left]] != num[right]) {
        		return false;
        	}
        	left ++;
        	right --;
        }
        return true;
    }
};