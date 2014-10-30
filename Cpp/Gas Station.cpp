#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int num=gas.size();
    int sum1=0,sum2=0;
    vector<int> vec;
    for(int i=0;i<num;i++){
        sum1+=gas[i];
        sum2+=cost[i];
        vec.push_back((gas[i]-cost[i]));
    }
    if(sum1<sum2) return -1;
    for(int i=0;i<num;i++){
        vec.push_back(vec[i]);
    }
    int sum,max;
    sum=max=-0xfffffff;
    int left,pos=0,cnt;
    for(int i=0;i<vec.size();i++){
        if(sum+vec[i]<vec[i]||pos>=num){
            sum=vec[i];
            cnt=i;
            pos=1;
        }
        else{
            pos++;
            sum=sum+vec[i];
        }
        if(max<sum){
            max=sum;
            left=cnt;
        }
    }
    return left;
}