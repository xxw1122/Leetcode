#include<iostream>
#include<cstring>

using namespace std;

int numTrees(int n)
    {
        if(n<=1) return 1;
        int arry[13];
        arry[0]=arry[1]=1;
        int sum=0;
        for(int i=2;i<=n;i++)
            {
                sum=0;
                for(int j=0;j<i;j++)
                    {
                        sum=sum+arry[j]*arry[i-j-1];
                    }
                arry[i]=sum;
            }
        return arry[n];
    }

int main()
    {
        int num;
        while(cin>>num)
            {
                cout<<numTrees(num)<<endl;
            }
        return 0;
    }