class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sums = (C - A) * (D - B) + (G - E) * (H - F);
        return sums - max(min(C, G) - max(A, E), 0) * max(min(D, H) - max(B, F), 0);
    }
};