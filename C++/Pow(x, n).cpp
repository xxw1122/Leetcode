#include <iostream>

using namespace std;


class Solution {
public:
    double p(double x, int n) {
        if(n==1) return x;
        if(n%2==0){
            double res=p(x,n/2);
            return res*res;
        }
        else{
            double res=p(x,(n-1)/2);
            return res*res*x;
        }
    }
    double pow(double x,int n){
        if(x==1) return 1.0;
        else if(x==-1){
            if(n%2==0) return 1;
            else return -1;
        }
        if(n>0) return p(x,n);
        else if(n<0) return (1.0)/p(x,-n);
        else return 1.0;
    }
};