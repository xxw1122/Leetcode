#include <cstring>
#include <string>
#include <unordered_set>

void generate(unordered_set<string>&dict,vector<string>&vec,const string &st,string str,int left,int right,int **dp){
  if(left==right){
    vec.push_back(str);
    return;
  }
  if(left>right) return;
  if(dp[left][right-1]==0) return;
  for(int i=left;i<right;i++){
    string s="";
    for(int j=left;j<=i;j++)
      s=s+st[j];
    if(dict.count(s)){
      s=str+s;
      if(i!=right-1) s=s+" ";
      generate(dict,vec,st,s,j+1,right,dp);
    }
  }
  return;
}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
  int len=s.size();
  int **dp=new int*[len];
  for(int i=0;i<len;i++)
    dp[i]=new int[len];
  memset(dp,0,sizeof(dp));
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
  vector<string>vec;
  string str="";
  if(dp[0][len-1]) generate(dict,vec,s,str,0,len,dp);
  return vec;
}
