#include <iostream>

using namespace std;

int divide(int dividend, int divisor) {
    int tag=0;
    long long cnt=dividend,cur=divisor;
    if(cnt<0&&cur<0){
        cnt=-cnt;
        cur=-cur;
    }
    else if(cnt<0&&cur>0){
        cnt=-cnt;
        tag=1;
    }
    else if(cnt>0&&cur<0){
        cur=-cur;
        tag=1;
    }
    if(cnt<cur) return 0;
    long long cnt1=cnt,cur1=cur;
    int num1=0,num2=1;
    while(cnt>=cur){
        if(cnt>=(cur<<1)){
            cur=cur<<1;
            num2=num2<<1;
        }
        else{
            cnt=cnt-cur;
            cur=cur1;
            num1=num1+num2;
            num2=1;
        }
    }
    if(tag) return -num1;
    else return num1;
}