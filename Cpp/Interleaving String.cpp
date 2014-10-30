#include <string>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
  int len1=s1.size(),len2=s2.size(),len3=s3.size();
  if(len1+len2!=len3) return false;
  int dp[500][500];
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  for(int i=0;i<=len1;i++){
    for(int j=0;j<=len2;j++){
        if(i>0&&s1[i-1]==s3[i+j-1]&&dp[i-1][j]){
            dp[i][j]=1;
        }
        if(j>0&&s2[j-1]==s3[i+j-1]&&dp[i][j-1]){
            dp[i][j]=1;
        }
    }
  }
  if(dp[len1][len2]) return true;
}
