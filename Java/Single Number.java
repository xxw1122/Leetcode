public class Solution {
  public int singleNumber(int[] A) {
    int n = A.length;
    int res = A[0];
    for(int i = 1; i < n; i++){
      res = res ^ A[i];
    }
    return res;
  }
}
