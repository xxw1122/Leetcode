#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
  int len=num.size();
  unordered_map<int,vector<int> >st;
  unordered_map<int,vector<int> >::iterator it;
  vector<int>::iterator it1;
  sort(num.begin(),num.end());
  for(int i=0;i<len;i++){
    if(st.count(num[i])==0){
      vector<int>vec1;
      vec1.push_back(i);
      st.insert(make_pair(num[i],vec1));
    }
    else{
      it=st.find(num[i]);
      vector<int> vec1;
      for(int j=0;j<((*it).second).size();j++){
        vec.push_back(((*it).second)[j]);
      }
      vec1.push_back(i);
      st.erase(it);
      st.insert(make_pair(num[i],vec1));
    }
  }
  vector<vector<int> >vec;
  for(int i=0;i<len;i++){
    for(int j=i+1;j<len;j++){
      int cnt=0-num[i]-num[j];
      if(st.count(cnt)){
        for(int k=0;k<st[cnt].size();k++){
          if(i!=st[cnt][k]&&j!=st[cnt][k]){
            vector<int> vec1;
            vec1.push_back(num[i]);
            vec1.push_back(num[j]);
            vec1.push_back(cnt);
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
