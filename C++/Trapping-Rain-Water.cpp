class Solution {
public:
    int trap(int A[], int n) {
        int *leftmaxhigh = new int[n];
        int leftmax = 0;
        for(int i = 0; i < n; i++){
            if(A[i] > leftmax) leftmax = A[i];
            leftmaxhigh[i] = leftmax;
        }
        int rightmax = 0, sum = 0;
        for(int i = n - 1; i >= 0; i--){
            if(A[i] < rightmax) rightmax = A[i];
            if(min(rightmax, leftmaxhigh[i]) > A[i])
                sum += min(rightmax, leftmaxhigh[i]) - A[i];
        }
        return sum;
    }
};