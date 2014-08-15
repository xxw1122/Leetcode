#include<iostream>
#include<vector>


int maxArea(vector<int> &height)
    {
        if(height.size()==0) return 0;
        int left=0,right=height.size()-1;
        int Area=0;
        while(left<=right)
            {
                int cnt=(right-left)*min(height[left],height[right]);
                if(cnt>Area) Area=cnt;
                if(height[left]<height[right]) left++;
                else right--;
            }
        return Area;
    }