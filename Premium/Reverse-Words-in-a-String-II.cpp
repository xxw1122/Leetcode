class Solution {
public:
	void reverse(string &s, int start, int end) {
		while (start < end) {
			char temp = s[start];
			s[start] = s[end];
			s[end] = temp;
			start ++;
			end --;
		}
	}
    void reverseWords(string &s) {
        int left = 0;
        for (int i = 0; i < s.size(); i ++) {
        	if (s[i] == ' ') {
        		reverse(s, left, i - 1);
        		left = i + 1;
        	}
        }
        reverse(s, left, s.size() - 1);
        reverse(s, 0, s.size() - 1);
    }
};