#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    int find(vector<int> vec,int target,int left,int right){
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(vec[mid]==target) return mid;
            else if(vec[mid]<target) left=mid+1;
            else if(vec[mid]>target) right=mid-1;
        }
        return -1;
    }
    static bool cmp(int x,int y){
        return x<y;
    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> vec(numbers);
        sort(vec.begin(),vec.end(),cmp);
        int len=vec.size();
        int x,y;
        for(int i=0;i<len;i++){
            int cnt=target-vec[i];
            int cur=find(vec,cnt,i+1,len-1);
            if(cur!=-1){
                x=vec[i];
                y=vec[cur];
                break;
            }
        }
        int a,b;
        int i,j;
        for(i=0;i<len;i++){
            if(numbers[i]==x){
                a=i+1;
                break;
            }
        }
        for(j=0;j<len;j++){
            if(numbers[j]==y&&j!=i){
                b=j+1;
                break;
            }
        }
        if(a>b) swap(a,b);
        vector<int> vt;
        vt.push_back(a);
        vt.push_back(b);
        return vt;
    }
};
