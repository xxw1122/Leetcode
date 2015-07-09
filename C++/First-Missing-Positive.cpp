class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int pos = 0;
        while(pos < n){
            int cnt = A[pos] - 1;
            if(A[pos] != pos + 1 && A[pos] >= 1 && A[pos] <= n && A[pos] != A[cnt]){
                swap(A[pos], A[cnt]);
            }
            else pos ++;
        }
        for(int i = 0; i < n; i++){
            if(A[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};