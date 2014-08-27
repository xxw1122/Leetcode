#include <iostream>
#include <string>

using namespace std;

int numDecodings(string s) {
    int len=s.size();
    if(len==0) return 0;
    int *dp=new int[len+1];
    fill(dp,dp+len+1,0);
    dp[0]=1;
    if(s[0]!='0') dp[1]=1;
    for(int i=2;i<=len;i++){
        int cnt=(s[i-2]-'0')*10+s[i-1]-'0';
        if(s[i-1]=='0'&&cnt<=26&&cnt>0){
            dp[i]=dp[i-2];
        }
        else if(s[i-1]!='0'&&s[i-2]!='0'&&cnt<=26&&cnt>0){
            dp[i]=dp[i-2]+dp[i-1];
        }
        else if(s[i-1]!='0'){
            dp[i]=dp[i-1];
        }
    }
    return dp[len];
}