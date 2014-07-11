#include<iostream>

using namespace std;

int arry[100];

int singlenumber(int *A,int n)
    {
        int sum=A[0];
        for(int i=1;i<n;i++)
            sum=sum^A[i];
        return sum;
    }

int main()
    {
        int num;
        while(cin>>num)
            {
                int cnt;
                for(int i=0;i<num;i++)
                    cin>>arry[i];
                cnt=singlenumber(arry, num);
                cout<<cnt<<endl;
            }
    }