#include<iostream>
#include<cstring>

using namespace std;


int main()
    {
        int num;
        while(cin>>num)
            {
                int arry[100];
                arry[1]=1,arry[2]=2;
                for(int i=3;i<=num;i++)
                    arry[i]=arry[i-1]+arry[i-2];
                return arry[num];
            }
        return 0;
    }