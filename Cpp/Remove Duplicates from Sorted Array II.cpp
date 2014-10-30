#include<iostream>


int removeDuplicates(int A[], int n)
    {
        if(n<=1) return n;
        int num=1,cnt=A[0],pos=0,res=1;
        for(int i=1;i<n;i++)
            {
                if(A[i]==A[pos]&&num==1)
                    {
                        A[++pos]=A[i];
                        num++;
                    }
                else if(A[i]!=A[pos])
                    {
                        A[++pos]=A[i];
                        num=1;
                    }
            }
        return pos+1;
    }