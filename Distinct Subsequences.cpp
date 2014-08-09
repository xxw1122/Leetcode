#include <iostream>
#include <string>

using namespace std;

int dp(int x,int y,const string &str1,const string &str2,int **d){
    if(d[x][y]!=-1) return d[x][y];
    if(x<y) return d[x][y]=0;
    if(x==0) return d[x][y]=1;
    if(str1[x-1]==str2[y-1]){
        d[x][y]=dp(x-1,y-1,str1,str2,d)+dp(x-1,y,str1,str2,d);
    }
    else{
        d[x][y]=dp(x-1,y,str1,str2,d);
    }
    return d[x][y];
}


int numDistinct(string S, string T) {
    int len1=S.size(),len2=T.size();
    int **d=new int*[len1+1];
    for(int i=0;i<len1+1;i++)
        d[i]=new int[len2+1];
    for(int i=0;i<len1+1;i++){
        for(int j=0;j<len2+1;j++){
            d[i][j]=-1;
        }
    }
    int cnt=dp(len1,len2,S,T,d);
    for(int i=0;i<len1+1;i++)
        delete []d[i];
    delete []d;
    return cnt;
}

int main(){
    string str1,str2;
    while(cin>>str1>>str2){
        int cnt=numDistinct(str1,str2);
        cout<<cnt<<endl;
    }
    return 0;
}