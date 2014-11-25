#include <algorithm>
#include <string>

using namespace std;

int factor(int pos){
    int num=1;
    for(int i=1;i<=pos;i++){
        num=num*i;
    }
    return num;
}

string getPermutation(int n, int k) {
    string str="";
    int vis[10];
    memset(vis,0,sizeof(vis));
    int pos=1,cnt=k;
    while(pos<=n){
        int cur=factor(n-pos);
        int t=cnt/cur,r=0;
        if(cnt%cur==0&&t!=0) t--;
        cnt=cnt-(t)*cur;
        char ch;
        for(int i=1;i<=n;i++){
            if(vis[i]==0&&r==t){
                ch='0'+i;
                str=str+ch;
                vis[i]=1;
                break;
            }
            else if(vis[i]==0){
                r++;
            }
        }
        pos++;
    }
}