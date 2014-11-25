#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class posIt>
bool permutation(posIt first,posIt last){
    if (first == last) return false;
    posIt i = last;
    if (first == --i) return false;
    posIt i1=i,i2=i;
    --i2;
    while(*i1<=(*i2)){
        if(i2==first) return false;
        --i1;
        --i2;
    }
    if(i1==i){
        iter_swap(i1, i2);
        return true;
    }
    int cnt=(*i2);
    posIt i3=i;
    while(*i3<=cnt){
        --i3;
    }
    iter_swap(i2,i3);
    reverse(i1,last);
    return true;
}

vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> >vec;
    if(num.size()==0) return vec;
    sort(num.begin(),num.end());
    vec.push_back(num);
    while(permutation(num.begin(), num.end())){
        vec.push_back(num);
    }
    return vec;
}