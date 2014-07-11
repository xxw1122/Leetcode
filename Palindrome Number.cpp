#include<iostream>

using namespace std;

bool isPalindrome(int x)
    {
        if(x==0) return true;
        if(x<0) return false;
        long long cnt=1,cur=10;
        for(int i=0;i<11;i++)
        {
            if(x/cnt==0) break;
            cnt=cnt*10;
        }
        cnt=cnt/10;
        while(cur<=cnt)
        {
            int left=x/cnt;
            x=x%cnt;
            int right=x%cur;
            if(left!=right) return false;
            x=x/cur;
            cur=cur;
            cnt=cnt/100;
        }
        return true;
    }


int main()
    {
        int num;
        while(cin>>num)
            {
                if(isPalindrome(num)) cout<<"yes"<<endl;
                else cout<<"no"<<endl;
            }
    }