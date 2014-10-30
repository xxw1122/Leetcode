#include <unordered_set>

int firstMissingPositive(int A[], int n) {
    int maxnum=-1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
      maxnum=max(maxnum,A[i]);
      st.insert(A[i]);
    }
    if(maxnum<=0) return 1;
    for(int i=1;i<=maxnum+1;i++){
      if(st.count(i)==0) return i;
    }
}
