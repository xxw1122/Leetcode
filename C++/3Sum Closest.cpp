#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int select(int x,int y,int target){
    int a=x-target;
    int b=y-target;
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(a>b) return y;
    else return x;
}

int search(vector<int> &num,int left,int right,int cnt){
    if(cnt>=num[right]) return num[right];
    if(cnt<=num[left]) return num[left];
    if(left==right) return num[left];
    int mid;
    while(left<right){
        mid=(left+right)/2;
        if(num[mid]==cnt) return num[mid];
        else if(num[mid]>cnt){
            if(mid>left&&num[mid-1]<=cnt){
                return select(num[mid-1],num[mid],cnt);
            }
            else{
                right=mid-1;
            }
        }
        else if(num[mid]<cnt){
            if(mid+1<right&&num[mid+1]>=cnt){
                return select(num[mid+1], num[mid], cnt);
            }
            else{
                left=mid+1;
            }
        }
    }
}

int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(),num.end());
    int len=num.size();
    int minval=99999999;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len-1;j++){
            int cnt=target-num[i]-num[j];
            int cur=search(num,j+1,len-1,cnt);
            int sum=cur+num[i]+num[j];
            minval=select(minval, sum, target);
        }
    }
    return minval;
}