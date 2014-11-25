#include<iostream>


int sqrt(int x)
    {
       if(x<=1) return x;
       //if(x==2147483647) return 46340;
        int left=1,right=46340,mid;
        while(left<=right)
            {
                mid=(left+right)/2;
                if(mid*mid==x) return mid;
                else if((mid*mid<x&&(mid+1)*(mid+1)>x)) return mid;
                else if(mid*mid<x) left=mid+1;
                else if(mid*mid>x) right=mid-1;
            }
    }