#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num){
    sort(num.begin(),num.end());
    vector<vector<int> >vec;
    int len=num.size();
    for(int i=0;i+2<len;i++){
        if(i>0&&num[i]==num[i-1])
                continue;
        int j=i+1,k=len-1;
        int cnt=-num[i];
        while(k>j){
            if(j>i+1&&num[j]==num[j-1]){
                j++;
                continue;
            }
            if(k<len-1&&num[k]==num[k+1]){
                k--;
                continue;
            }
            int cur=num[j]+num[k];
            if(cur>cnt){
                k--;
            }
            else if(cur<cnt){
                j++;
            }
            else if(cur==cnt){
                vector<int> vec1;
                vec1.push_back(num[i]);
                vec1.push_back(num[j]);
                vec1.push_back(num[k]);
                vec.push_back(vec1);
                j++;
            }
        }
    }
    return vec;
}