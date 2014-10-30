#include<iostream>
#include<cstring>

using namespace std;

int arry[100];

int singleNumberII_36(int A[], int n)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int c = 0, d = 1<<i;
        for (int j = 0; j < n; j++)
            if (A[j] & d) c++;
        if (c%3) ans |= d;
    }
    return ans;
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