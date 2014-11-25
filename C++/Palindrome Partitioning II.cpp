#include <iostream>
#include <string>

using namespace std;


int minCut(string s) {
    int len=s.size();
    if(len==1) return 0;
    int **dp=new int*[len+2];
    for(int i=0;i<len+2;i++){
        dp[i]=new int[len+2];
    }
    for(int i=0;i<len+2;i++){
        for(int j=0;j<len+2;j++){
            dp[i][j]=0;
        }
    }
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
    int *d=new int[len+2];
    d[0]=0;
    int ans=len+1,cnt;
    for(int i=1;i<len;i++){
        if(dp[0][i]){
            d[0]=0;
        }
        else{
            ans=len+1;
            for(int k=0;k<i;k++){
                if(dp[k+1][i]){
                    cnt=d[k]+1;
                }
                else{
                    cnt=d[k]+i-k;
                }
                ans=min(ans,cnt);
            }
            d[i]=ans;
        }
    }
    return d[len-1];
}