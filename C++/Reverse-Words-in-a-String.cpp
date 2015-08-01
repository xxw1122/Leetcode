class Solution {
public:
    void reverse(string &s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            left ++;
            right --;
        }
    }
    void reverseWords(string &s) {
    }
};