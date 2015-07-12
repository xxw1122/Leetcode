class Solution {
public:
    bool isok(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) return true;
        else return false;
    }
    bool is_equal(char ch1,char ch2){
        if(ch1 == ch2) return true;
        else if(ch1 - ch2 == 32 || ch2 - ch1 == 32) return true;
        else return false;
    }
    bool isPalindrome(string s) {
        int left=0, right = s.size() - 1;
        int len = s.size();
        while(left < right && left < len && right >= 0){
            while(left < len && !isok(s[left]))
                left++;
            while(right > 0 && !isok(s[right]))
                right--;
            if(left >= right) return true;
            if(!is_equal(s[left], s[right])) return false;
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};