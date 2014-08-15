#include <iostream>

using namespace std;

int jump(int A[], int n) {
    int max = 0;
    int f[n];
    memset(f, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        for (int j = max - i + 1; j <= A[i] && i + j < n; j++) {
            f[i + j] = f[i] + 1;
        }
        max = max > A[i] + i ? max : A[i] + i;
    }
    return f[n - 1];
}