#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int dp[1010][1010];
    memset(dp,0,sizeof(dp));
    int len=s.size();
    for(int i=0;i<=len;i++){
        dp[i][i]=1;
    }
    for(int i=2;i<=len;i++){
        for(int j=0;j+i-1<len;j++){
            int r=j+i-1;
            if(s[j]==s[r]){
                if(j+1>=r-1) dp[j][r]=1;
                else if(dp[j+1][r-1]) dp[j][r]=1;
            }
        }
    }
    int maxlen=0,left=0,right=0;
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            if(dp[i][j]){
                if(j-i+1>maxlen){
                    left=i;
                    right=j;
                    maxlen=j-i+1;
                }
            }
        }
    }
    string str;
    for(int i=left;i<=right;i++){
        str=str+s[i];
    }
    return str;
}