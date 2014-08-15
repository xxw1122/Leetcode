#include <cstring>
#include <string>
#include <unordered_set>


using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
  int dp[1000][1000];
  memset(dp,0,sizeof(dp));
  int len=s.size();
  for(int i=0;i<len;i++){
    string str;
    str=str+s[i];
    if(dict.count(str)){
      dp[i][i]=1;
    }
  }
  for(int i=2;i<=len;i++){
    for(int j=0;j+i-1<len;j++){
      string str;
      int r=j+i-1;
      for(int h=j;h<=r;h++)
        str=str+s[h];
      if(dict.count(str)){
        dp[j][r]=1;
        continue;
      }
      for(int k=j;k<=r-1;k++){
        dp[j][r]=(dp[j][r]|(dp[j][k]&dp[k+1][r]));
      }
    }
  }
  if(dp[0][len-1]) return true;
  else return false;
}
