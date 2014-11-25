#include <string>
#include <cstring>

bool isScramble(string s1, string s2) {
    if(s1.size()!=s2.size()) return false;
    if(s1==s2) return true;
    int A[26],B[26];
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    for(int i=0;i<s1.size();i++){
        A[s1[i]-'a']++;
        B[s2[i]-'a']++;
    }
    for(int i=0;i<26;i++)
        if(A[i]!=B[i]) return false;
    for(int i=1;i<s1.size();i++){
        bool result = isScramble(s1.substr(0,i), s2.substr(0,i))
            && isScramble(s1.substr(i), s2.substr(i));
        result = result || (isScramble(s1.substr(0,i), s2.substr(s2.length()-i, i))
            && isScramble(s1.substr(i), s2.substr(0,s2.length()-i)));
        if(result) return true;
    }
    return false;
}