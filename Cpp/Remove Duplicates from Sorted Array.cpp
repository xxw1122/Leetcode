#include<iostream>

using namespace std;

int removeDuplicates(int A[], int n)
    {
        int cnt=1,cur=A[0];
        for(int i=1;i<n;i++)
            {
                if(A[i]!=cur)
                    {
                        A[cnt++]=A[i];
                        cur=A[i];
                    }
            }
        return cnt;
    }