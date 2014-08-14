#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int> > fourSum(vector<int>&num,int target){
  unordered_map<int,vector<pair<int,int> > >st;
  sort(num.begin(),num.end());
  int len=num.size();
  unordered_map<int,vector<pair<int,int> > >::iterator it;
  vector<vector<int> >::iterator it1;
  for(int i=0;i<len;i++){
    for(int j=i+1;j<len;j++){
      int cnt=num[i]+num[j];
      if(st.count(cnt)==0){
        vector<pair<int,int> > cur;
        cur.push_back(make_pair(i,j));
        st.insert(make_pair(cnt,cur));
      }
      else{
        vector<pair<int,int> >cur;
        it=st.find(cnt);
        for(int k=0;k<((*it).second).size();k++)
          cur.push_back(((*it).second)[k]);
        cur.push_back(make_pair(i,j));
        st.erase(it);
        st.insert(make_pair(cnt,cur));
      }
    }
  }
  vector<vector<int> >vec;
  for(int i=0;i<len;i++){
    for(int j=i+1;j<len;j++){
      int cnt=target-num[i]-num[j];
      if(st.count(cnt)>0){
        for(int k=0;k<st[cnt].size();k++){
          vector<int> vec1;
          int x=st[cnt][k].first,y=st[cnt][k].second;
          if(x!=i&&y!=j&&x!=j&&y!=i){
            vec1.push_back(num[i]);
            vec1.push_back(num[j]);
            vec1.push_back(num[x]);
            vec1.push_back(num[y]);
            sort(vec1.begin(),vec1.end());
            vec.push_back(vec1);
          }
        }
      }
    }
  }
  sort(vec.begin(),vec.end());
  it1=unique(vec.begin(),vec.end());
  vector<vector<int> >vec1(vec.begin(),it1);
  return vec1;
}
