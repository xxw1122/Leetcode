#include <vector>

int candy(vector<int> &ratings) {
    int len=ratings.size();
    int vis[len];
    memset(vis,0,sizeof(int)*len);
    int k=1;
    for(int i=1;i<len;i++){
        if(ratings[i]>ratings[i-1]){
            vis[i]=max(vis[i],k++);
        }
        else{
            k=1;
        }
    }
    k=1;
    for(int i=len-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            vis[i]=max(vis[i],k++);
        }
        else{
            k=1;
        }
    }
    int cost=len;
    for(int i=0;i<len;i++)
        cost+=vis[i];
    return 0;
}