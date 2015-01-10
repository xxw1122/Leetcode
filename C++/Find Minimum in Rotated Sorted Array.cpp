#include <vector>

class Solution {
public:
    int findMin(vector<int> &num) {
        int len = num.size();
        int left = 0, right = len - 1, mid;
        while(left < right && num[left] > num[right]){
            mid = (left + right) / 2;
            if(num[mid] < num[right]) right = mid;
            else left = mid + 1;
        }
        return num[left];
    }
};