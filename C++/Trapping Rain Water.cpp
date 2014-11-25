#include <iostream>

using namespace std;

int calculate(int start,int end,int A[]){
    int sum=0;
    int height=min(A[start],A[end]);
    int cnt=(end-start-1)*height;
    for(int i=start+1;i<end;i++){
        if(A[i]<=height) sum=sum+A[i];
        else sum=sum+height;
    }
    return cnt-sum;
}

int trap(int A[], int n) {
    int sum=0;
    int start,cnt,end;
    for(int i=0;i<n;i++){
        if(A[i]!=0){
            start=i;
            break;
        }
    }
    if(start>=n-1) return sum;
    cnt=start+1;
    while(cnt<n){
        int tag=1;
        int index;
        for(int i=cnt;i<n;i++){
            if(A[i]>=A[start]){
                index=i;
                tag=0;
                break;
            }
        }
        if(tag==0){
            sum=sum+calculate(start, index, A);
            start=index;
            cnt=start+1;
        }
        else{
            int maxh=A[cnt];
            index=cnt;
            for(int i=cnt;i<n;i++){
                if(A[i]>maxh){
                    maxh=A[i];
                    index=i;
                }
            }
            sum=sum+calculate(start, index, A);
            start=index;
            cnt=start+1;
        }
    }
    return sum;
}