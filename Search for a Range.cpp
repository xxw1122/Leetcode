#include<iostream>
#include<vector>

int findleft(int A[],int n,int target)
    {
        int left=0,right=n-1;
        int mid;
        while(left<=right)
            {
                mid=(left+right)/2;
                if(A[mid]==target)
                    {
                        if(mid==0||A[mid-1]!=target) return mid;
                        else right=mid-1;
                    }
                else if(A[mid]<target) left=mid+1;
                else if(A[mid]>target) right=mid-1;
            }
        return -1;
    }

int findright(int A[],int n,int target)
    {
        int left=0,right=n-1;
        int mid;
        while(left<=right)
            {
                mid=(left+right)/2;
                if(A[mid]==target)
                    {
                        if(mid==n-1||A[mid+1]!=target) return mid;
                        else left=mid+1;
                    }
                else if(A[mid]<target) left=mid+1;
                else if(A[mid]>target) right=mid-1;
            }
        return -1;
    }

vector<int> searchRange(int A[], int n, int target)
    {
        int pos1=findleft(A,n,target);
        int pos2=findright(A,n,target);
        vector<int> vec;
        vec.push_back(pos1);
        vec.push_back(pos2);
        return vec;
    }