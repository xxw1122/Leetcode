#include<iostream>

using namespace std;

int binarysearch(int left,int right,int A[],int target)
    {
        int mid;
        while(left<=right)
            {
                mid=(left+right)/2;
                if(A[mid]==target) return mid;
                else if(A[mid]<target)
                    {
                        left=mid+1;
                    }
                else
                    {
                        right=mid-1;
                    }
            }
        if(left==right+1)
            {
                return left;
            }
        else if(left+1==right)
            {
                return right;
            }
    }


int searchInsert(int A[], int n, int target)
    {
        int pos=binarysearch(0, n-1, A, target);
        return pos;
    }