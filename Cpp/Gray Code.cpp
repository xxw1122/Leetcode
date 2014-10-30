#include<iostream>
#include<vector>
#include<cstring>

int conv(int A[],int len)
    {
        int sum=0;
        for(int i=0;i<len;i++)
            sum=sum*2+A[i];
        return sum;
    }

int convert(int num,int len)
    {
        int arry[100];
        memset(arry,0,sizeof(arry));
        int pos=0;
        arry[pos++]=num%2;
        num=num/2;
        while(num!=0)
            {
                arry[pos++]=num%2;
                num=num/2;
            }
        int *arry1=new int[len];
        pos=0;
        int cur=len-1;
        if(arry[cur]==0) arry1[pos++]=0;
        else arry1[pos++]=1;
        cur--;
        while(cur>=0)
            {
                if(arry[cur]==arry[cur+1]) arry1[pos++]=0;
                else arry1[pos++]=1;
                cur--;
            }
        int s=conv(arry1,len);
        delete [] arry1;
        return s;
    }

vector<int> grayCode(int n)
    {
        int cnt=1;
        vector<int> vec;
        if(n==0) return vec;
        for(int i=0;i<n;i++)
            cnt=cnt*2;
        for(int i=0;i<cnt;i++)
            {
                int t=convert(i);
                vec.push_back(t);
            }
        return vec;
    }