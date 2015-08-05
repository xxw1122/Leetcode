class Solution {
public:
    int format(string& s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ' || (i > 0 && s[i-1] != ' ')) {
                s[count++] = s[i];
            }
        }
        // handle the case where after last word, all were spaces
        if (s[count-1] == ' ') count--;
        s.resize(count);
        return count;
    }

    void reverseWords(string &s) {
        int n = format(s); // remove all trailing and preceding spaces
        if (n == 0) return;
        // reverse the whole string
        for (int i = 0; i < n/2; ++i) {
            swap(s[i], s[n-i-1]);
        }
        int i = 0;
        // reverse each word
        while(i < n) {
            int j = i;
            size_t end = s.find_first_of(' ',i); 
            i = (end == string::npos) ? n : end;
            int e = i-1;
            while(j < e) {
                swap(s[j],s[e]);
                j++;
                e--;
            }
            i++;
        }
    }
};