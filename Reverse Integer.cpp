#include<iostream>
#include<cstring>

using namespace std;

int reverse(int cnt)
    {
        int tag=0;
        int arry[20];
        memset(arry,0,sizeof(arry));
        if(cin<0)
            {
                tag=1;
                cnt=cnt*-1;
            }
        int pos=0,sum=0;
        while(cnt)
            {
                arry[pos++]=cnt%10;
                cnt=cnt/10;
            }
        for(int i=0;i<pos;i++)
            sum=sum*10+arry[i];
        if(tag) sum=sum*-1;
        return sum;
    }


int main()
    {
        int num;
        while(cin>>num)
            {
                cout<<reverse(num)<<endl;
            }
    }