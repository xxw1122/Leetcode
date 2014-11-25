#include<iostream>
#include<cstring>

using namespace std;

int arry[1000];

int maxSubArray(int A[], int n)
    {
        int sum=A[0],maxsum=A[0];
        for(int i=1;i<n;i++)
            {
                if(sum<0) sum=0;
                sum=A[i]+sum;
                if(sum>maxsum) maxsum=sum;
            }
        return maxsum;
    }

int main()
    {
        int num;
        while(cin>>num&&num)
            {
                for(int i=0;i<num;i++)
                    cin>>arry[i];
            }
        return 0;
    }