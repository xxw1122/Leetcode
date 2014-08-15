#include<iostream>

bool canJump(int A[], int n)
    {
        int cnt=A[0];
        for(int i=1;i<=cnt;i++)
            {
                if(A[i]+i>cnt) cnt=A[i]+i;
                if(cnt>=n-1) return true;
            }
        return false;
    }