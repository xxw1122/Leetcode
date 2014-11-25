#include<iostream>

void rev(int A[],int begin,int end)
    {
        if(begin>=end) return;
        int mid=(begin+end+1)/2;
        for(int i=begin;i<mid;i++)
            {
                int cnt=A[i];
                A[i]=A[end-i+begin];
                A[end-i+begin]=cnt;
            }
    }

bool search(int A[], int n, int target)
    {
        int i=0;
        for(i=1;i<n;i++)
            {
                if(A[i]<A[i-1]) break;
            }
        rev(A,0,i-1);
        rev(A,i,n-1);
        rev(A,0,n-1);
        int left=0,right=n-1;
        int mid;
        while(left<=right)
            {
                mid=(right+left)/2;
                if(A[mid]==target) return true;
                else if(A[mid]>target) right=mid-1;
                else left=mid+1;
            }
        return false;
    }